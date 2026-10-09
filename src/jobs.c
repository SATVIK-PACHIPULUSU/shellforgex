#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "jobs.h"

#define MAX_JOBS 64

typedef struct
{
    pid_t pid;
    char command[1024];
    int active;
} Job;

static Job jobs[MAX_JOBS];
static int job_count = 0;

void add_job(pid_t pid, const char *command)
{
    if (job_count >= MAX_JOBS)
    {
        return;
    }

    jobs[job_count].pid = pid;
    strncpy(jobs[job_count].command, command, sizeof(jobs[job_count].command) - 1);
    jobs[job_count].command[sizeof(jobs[job_count].command) - 1] = '\0';
    jobs[job_count].active = 1;

    printf("[%d] %d\n", job_count + 1, pid);

    job_count++;
}

void show_jobs(void)
{
    for (int i = 0; i < job_count; i++)
    {
        if (jobs[i].active)
        {
            printf("[%d] %d Running %s\n",
                   i + 1,
                   jobs[i].pid,
                   jobs[i].command);
        }
    }
}

void reap_jobs(void)
{
    for (int i = 0; i < job_count; i++)
    {
        if (jobs[i].active)
        {
            int status;
            pid_t result = waitpid(jobs[i].pid, &status, WNOHANG);

            if (result == jobs[i].pid)
            {
                jobs[i].active = 0;
                printf("[%d] Done %s\n", i + 1, jobs[i].command);
            }
        }
    }
}
void print_jobs_tree(pid_t shell_pid)
{
    printf("%d (ShellForge)\n", shell_pid);
    
    int active_count = 0;
    for (int i = 0; i < job_count; i++)
    {
        if (jobs[i].active)
        {
            active_count++;
        }
    }

    int printed = 0;
    for (int i = 0; i < job_count; i++)
    {
        if (jobs[i].active)
        {
            printed++;
            if (printed == active_count)
            {
                printf("      └── %d  %s\n", jobs[i].pid, jobs[i].command);
            }
            else
            {
                printf("      ├── %d  %s\n", jobs[i].pid, jobs[i].command);
            }
        }
    }

    if (active_count == 0)
    {
        printf("      └── (No active background jobs)\n");
    }
}
