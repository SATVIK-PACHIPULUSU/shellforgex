#include <stdio.h>
#include <string.h>

#include "parser.h"

void parse_command(char *input, char *args[], int max_args)
{
    int count = 0;

    char *token = strtok(input, " ");

    while (token != NULL && count < max_args - 1)
    {
        args[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    args[count] = NULL;
}

int split_pipeline(char *input, char *commands[], int max_commands)
{
    int count = 0;

    char *command = strtok(input, "|");

    while (command != NULL && count < max_commands)
    {
        while (*command == ' ')
        {
            command++;
        }

        commands[count] = command;
        count++;

        command = strtok(NULL, "|");
    }

    return count;
}
