/*
** EPITECH PROJECT, 2021
** navy
** File description:
** check_win.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

extern int global_sig;

void set_global(struct sigaction *sig1, struct sigaction *sig2)
{
    global_sig = 0;
    sigaction(SIGUSR1, sig1, NULL);
    sigaction(SIGUSR2, sig2, NULL);
    while (global_sig == 0)
        pause();
}

bool first_check(game_t *infos, struct sigaction sig1, struct sigaction sig2,
bool *bol)
{
    int win = 0;

    if (infos->tour == 2 && infos->player == 1) {
        usleep(100000);
        if (infos->win) {
            my_putstr("\nEnemy won\n\n");
            win = 1;
            *bol = true;
            kill_ft(infos->enemy_pid, 1);
        } else
            kill_ft(infos->enemy_pid, 2);
    }
    if (infos->tour == 2 && infos->player == 2) {
        set_global(&sig1, &sig2);
        if (global_sig == 2) {
            infos->win = true;
            my_putstr("\nI won\n\n");
            *bol = true;
        }
    }
    return (win);
}

int second_check(game_t *infos, struct sigaction sig1, struct sigaction sig2,
bool bol)
{
    int win = 0;

    if (infos->tour == 2 && infos->player == 2) {
        usleep(100000);
        if (infos->win) {
            !bol ? my_putstr("\nEnemy won\n\n"), (win = 1) : 0;
            kill_ft(infos->enemy_pid, 1);
        } else
            kill_ft(infos->enemy_pid, 2);
    }
    if (infos->tour == 2 && infos->player == 1) {
        set_global(&sig1, &sig2);
        if (global_sig == 2) {
            infos->win = true;
            !bol ? my_putstr("\nI won\n\n") : (win = 1);
            return (win);
        }
    }
    return (win);
}

void check_win_handler(int sig)
{
    if (sig == SIGUSR1)
        global_sig = 2;
    else
        global_sig = 1;
}

int check_win2(game_t *infos)
{
    struct sigaction sig1;
    struct sigaction sig2;
    bool bol = false;
    int win = 0;

    init_sig(&sig1, check_win_handler, false);
    init_sig(&sig2, check_win_handler, false);
    win = first_check(infos, sig1, sig2, &bol);
    usleep(10000);
    win = second_check(infos, sig1, sig2, bol);
    return (win);
}
