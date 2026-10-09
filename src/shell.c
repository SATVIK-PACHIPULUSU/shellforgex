#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "process.h"
#include "builtin.h"
#include "history.h"
#include "pipeline.h"
#include "redirection.h"
#include "jobs.h"
#include "memstat.h"
#include "sync_demo.h"
#include "dashboard.h"
#include "ai.h"

void run_shell(void)
{
    char input[1024];

    printf("===================================\n");
    printf("      ShellForge X v1.0\n");
    printf("===================================\n");

    while (1)
    {
        reap_jobs();

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

        add_history(input);

        if (strcmp(input, "history") == 0)
        {
            show_history();
            continue;
        }

        if (strcmp(input, "jobs") == 0)
        {
            show_jobs();
            continue;
        }
	if (strcmp(input, "memstat") == 0)
        {
            execute_memstat(NULL);
            continue;
        }

        if (strncmp(input, "memstat ", 8) == 0)
        {
            execute_memstat(input + 8);
            continue;
        }
	if (strcmp(input, "deadlock") == 0)
        {
            execute_deadlock();
            continue;
        }
	if (strcmp(input, "dashboard") == 0)
        {
            execute_dashboard();
            continue;
        }
	if (strncmp(input, "ai ", 3) == 0)
        {
            execute_ai(input + 3);
            continue;
        }
        if (strcmp(input, "cd") == 0)
        {
            builtin_cd(NULL);
            continue;
        }

        if (strncmp(input, "cd ", 3) == 0)
        {
            builtin_cd(input + 3);
            continue;
        }

        if (strchr(input, '>') != NULL || strchr(input, '<') != NULL)
        {
            execute_redirection(input);
            continue;
        }

        if (strchr(input, '|') != NULL)
        {
            execute_pipeline(input);
            continue;
        }

        execute_command(input);
    }
}
