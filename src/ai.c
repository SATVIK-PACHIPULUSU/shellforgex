#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ai.h"

void execute_ai(char *prompt)
{
    if (prompt == NULL || strlen(prompt) == 0)
    {
        printf("Usage: ai <what you want to do>\n");
        return;
    }

    char command[2048];
    snprintf(command, sizeof(command), "python3 ai_helper.py \"%s\"", prompt);

    printf("Thinking...\n");

    FILE *fp = popen(command, "r");
    if (fp == NULL)
    {
        perror("ShellForge: ai");
        return;
    }

    char buffer[1024];
    printf("\n--- AI Suggestion ---\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }
    printf("---------------------\n");

    pclose(fp);
}
