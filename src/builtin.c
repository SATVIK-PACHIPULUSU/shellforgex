#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "builtin.h"

void builtin_cd(char *path)
{
    if (path == NULL)
    {
        path = getenv("HOME");
    }

    if (path == NULL)
    {
        fprintf(stderr, "ShellForge: cd: HOME not set\n");
        return;
    }

    if (chdir(path) == -1)
    {
        perror("ShellForge: cd");
    }
}
