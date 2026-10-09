#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <unistd.h>

#include "signals.h"

static void handle_sigint(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\n", 1);
}

static void handle_sigterm(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\nShellForge: SIGTERM received\n", 31);
}

void setup_signal_handlers(void)
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    sa.sa_handler = handle_sigterm;
    sigaction(SIGTERM, &sa, NULL);
}
