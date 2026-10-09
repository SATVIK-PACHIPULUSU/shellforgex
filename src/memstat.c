#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memstat.h"

void execute_memstat(char *pid_str)
{
    char path[256];

    if (pid_str == NULL || strlen(pid_str) == 0)
    {
        snprintf(path, sizeof(path), "/proc/self/status");
    }
    else
    {
        snprintf(path, sizeof(path), "/proc/%s/status", pid_str);
    }

    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        perror("ShellForge: memstat");
        return;
    }

    printf("Memory Status for %s:\n", (pid_str && strlen(pid_str) > 0) ? pid_str : "ShellForge (self)");
    printf("-----------------------------------\n");

    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
        if (strncmp(line, "VmSize:", 7) == 0 ||
            strncmp(line, "VmRSS:", 6) == 0 ||
            strncmp(line, "VmData:", 7) == 0 ||
            strncmp(line, "VmStk:", 6) == 0 ||
            strncmp(line, "VmExe:", 6) == 0)
        {
            printf("%s", line);
        }
    }

    fclose(fp);
}
