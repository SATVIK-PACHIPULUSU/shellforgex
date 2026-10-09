#include "shell.h"
#include "signals.h"

int main(void)
{
    setup_signal_handlers();
    run_shell();

    return 0;
}
