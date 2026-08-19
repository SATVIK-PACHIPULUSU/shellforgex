#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Provides fork(), execvp(), pid_t
#include <sys/wait.h>   // Provides waitpid()
#include "process.h"

void execute_command(char *command)
{
    // execvp expects an array of strings, terminated by a NULL pointer.
    // For now, we only handle a single command with NO arguments.
    char *args[2];
    args[0] = command;  // e.g., "ls"
    args[1] = NULL;     // Tells execvp where the array ends
    pid_t pid = fork();

    if (pid == -1)
    {

        perror("ShellForge: fork failed");
    }
    else if (pid == 0)
    {
       
        if (execvp(args[0], args) == -1)
        {
            perror("ShellForge");
            exit(EXIT_FAILURE); // Terminate the broken child
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}
