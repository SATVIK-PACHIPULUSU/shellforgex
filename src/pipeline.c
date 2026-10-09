#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pipeline.h"
#include "parser.h"

#define MAX_COMMANDS 32
#define MAX_ARGS 64

void execute_pipeline(char *input)
{
    char *commands[MAX_COMMANDS];
    int command_count = split_pipeline(input, commands, MAX_COMMANDS);

    if (command_count <= 0)
    {
        return;
    }

    int pipes[MAX_COMMANDS - 1][2];
    pid_t pids[MAX_COMMANDS];

    for (int i = 0; i < command_count - 1; i++)
    {
        if (pipe(pipes[i]) == -1)
        {
            perror("ShellForge: pipe");
            return;
        }
    }

    for (int i = 0; i < command_count; i++)
    {
        pids[i] = fork();

        if (pids[i] == -1)
        {
            perror("ShellForge: fork");

            for (int j = 0; j < command_count - 1; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            return;
        }

        if (pids[i] == 0)
        {
            if (i > 0)
            {
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }

            if (i < command_count - 1)
            {
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            for (int j = 0; j < command_count - 1; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            char *args[MAX_ARGS];
            parse_command(commands[i], args, MAX_ARGS);

            if (args[0] == NULL)
            {
                exit(EXIT_FAILURE);
            }

            execvp(args[0], args);

            perror("ShellForge");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < command_count - 1; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    for (int i = 0; i < command_count; i++)
    {
        waitpid(pids[i], NULL, 0);
    }
}
