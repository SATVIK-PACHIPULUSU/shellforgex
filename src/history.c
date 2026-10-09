#include <stdio.h>
#include <string.h>

#include "history.h"

#define MAX_HISTORY 100
#define MAX_COMMAND_LENGTH 1024

static char history[MAX_HISTORY][MAX_COMMAND_LENGTH];
static int history_count = 0;

void add_history(const char *command)
{
    if (history_count < MAX_HISTORY)
    {
        strncpy(history[history_count], command, MAX_COMMAND_LENGTH - 1);
        history[history_count][MAX_COMMAND_LENGTH - 1] = '\0';
        history_count++;
    }
}

void show_history(void)
{
    for (int i = 0; i < history_count; i++)
    {
        printf("%d  %s\n", i + 1, history[i]);
    }
}
