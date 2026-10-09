#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#include "redirection.h"
#include "parser.h"

void execute_redirection(char *input)
{
    char *args[64];
    char *redirect = NULL;
    char *filename;
    int fd;
    int append = 0;
    int input_redirect = 0;

    if ((redirect = strstr(input, ">>")) != NULL)
    {
        append = 1;
        *redirect = '\0';
        redirect += 2;
    }
    else if ((redirect = strchr(input, '>')) != NULL)
    {
        *redirect = '\0';
        redirect++;
    }
    else if ((redirect = strchr(input, '<')) != NULL)
    {
        input_redirect = 1;
        *redirect = '\0';
        redirect++;
    }
    else
    {
        return;
    }

    while (*redirect == ' ' || *redirect == '\t')
    {
        redirect++;
    }

    filename = strtok(redirect, " \t");

    if (filename == NULL)
    {
        fprintf(stderr, "ShellForge: missing file name\n");
        return;
    }

    while (*input == ' ' || *input == '\t')
    {
        input++;
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
        if (input_redirect)
        {
            fd = open(filename, O_RDONLY);
        }
        else if (append)
        {
            fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
        }
        else
        {
            fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }

        if (fd == -1)
        {
            perror("ShellForge: open");
            exit(EXIT_FAILURE);
        }

        if (input_redirect)
        {
            dup2(fd, STDIN_FILENO);
        }
        else
        {
            dup2(fd, STDOUT_FILENO);
        }

        close(fd);

        execvp(args[0], args);

        perror("ShellForge");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, NULL, 0);
}
