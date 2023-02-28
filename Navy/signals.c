/*
** EPITECH PROJECT, 2021
** signals.c
** File description:
** signal management
*/

#include <unistd.h>
#include <signal.h>
#include "includes/my_lib.h"
#include "includes/navy.h"

void handle_signal(int signal, siginfo_t *si, void *context)
{
    (void)context;
    if (signal == SIGUSR1 && global_navy.enemy_pid == si->si_pid)
        global_navy.num_sig1++;
    else if (signal == SIGUSR2 && global_navy.enemy_pid == si->si_pid) {
        global_navy.num_sig2++;
        global_navy.num_sig1_saved = global_navy.num_sig1;
        global_navy.num_sig1 = 0;
    }
    if (signal == SIGUSR2 && global_navy.enemy_pid == 0) {
        global_navy.num_sig2++;
        global_navy.enemy_pid = si->si_pid;
    }
}

int init_signals(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_mask = mask;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        my_putstr("Error setting sigaction for SIGUSR1\n");
        return -1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        my_putstr("Error setting sigaction for SIGUSR2\n");
        return -1;
    }
    return 0;
}

int wait_signal_usr2(void)
{
    int ret = 0;

    while (global_navy.num_sig2 == 0)
        pause();
    ret = global_navy.num_sig1_saved;
    global_navy.num_sig2 = 0;
    return ret;
}
