#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "process.h" 

void run_shell(void)
{
    char input[1024];

    printf("===================================\n");
    printf("      ShellForge X v1.0\n");
    printf("===================================\n");

    while (1)
    {
        printf("\nShellForge> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
        {
            continue;
        }

        if (strcmp(input, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

     
     
        execute_command(input);
    }
}
