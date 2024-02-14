/*
** EPITECH PROJECT, 2021
** navy
** File description:
** handlers_sig.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

extern int global_sig;

void init_sig(struct sigaction *sig, void (*funct) (int), bool sigact)
{
    sig->sa_handler = funct;
    sig->sa_flags = SA_SIGINFO;
    if (sigact)
        sig->sa_sigaction = get_sig_pid;
    sigemptyset(&sig->sa_mask);
}

void get_sig_pid(int sig, siginfo_t *info, void *context)
{
    global_sig = info->si_pid;
}

void handler_recieve_hit_summary(int sig)
{
    if (sig == SIGUSR1)
        global_sig = 2;
    else if (sig == SIGUSR2)
        global_sig = 1;
}

void kill_ft(int enemy_pid, int usr)
{
    if (usr == 1)
        kill(enemy_pid, SIGUSR1);
    else if (usr == 2)
        kill(enemy_pid, SIGUSR2);
    usleep(10000);
}
