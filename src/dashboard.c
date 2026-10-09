#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "dashboard.h"
#include "jobs.h"

void execute_dashboard(void)
{
    pid_t shell_pid = getpid();
    pid_t parent_pid = getppid();

    printf("\n===========================================\n");
    printf("          SHELLFORGE X DASHBOARD           \n");
    printf("===========================================\n");
    printf("Process Tree Visualization:\n");
    printf("%d (Parent Process)\n", parent_pid);
    printf(" │\n");
    printf(" └── ");
    print_jobs_tree(shell_pid);
    printf("===========================================\n\n");
}
