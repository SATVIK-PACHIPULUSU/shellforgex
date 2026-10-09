#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "process.h"
#include "parser.h"
#include "jobs.h"

void execute_command(char *input)
{
    char *args[64];
    int background = 0;
    int len = strlen(input);

    while (len > 0 && (input[len - 1] == ' ' || input[len - 1] == '\t'))
    {
        input[len - 1] = '\0';
        len--;
    }

    if (len > 0 && input[len - 1] == '&')
    {
        background = 1;
        input[len - 1] = '\0';
    }

    parse_command(input, args, 64);

    if (args[0] == NULL)
    {
        return;
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("ShellForge: fork");
        return;
    }

    if (pid == 0)
    {
        execvp(args[0], args);
        perror("ShellForge");
        exit(EXIT_FAILURE);
    }

    if (background)
    {
        add_job(pid, input);
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}
