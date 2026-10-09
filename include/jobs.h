#ifndef JOBS_H
#define JOBS_H

#include <sys/types.h>

void add_job(pid_t pid, const char *command);
void show_jobs(void);
void reap_jobs(void);
void print_jobs_tree(pid_t shell_pid);

#endif
