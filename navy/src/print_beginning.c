/*
** EPITECH PROJECT, 2021
** navy
** File description:
** print_beginning.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

extern int global_sig;

void handler_player1(int sig)
{
    my_putstr("enemy connected\n\n");
}

void handler_player2(int sig)
{
    my_putstr("successfully connected\n\n");
    global_sig = 1;
}

void begin_usr1(struct sigaction sig1, struct sigaction sig2, game_t *infos)
{
    my_putstr("waiting for enemy connection...\n\n");
    sigaction(SIGUSR1, &sig1, NULL);
    pause();
    infos->enemy_pid = global_sig;
    global_sig = 0;
    usleep(10000);
    kill(infos->enemy_pid, SIGUSR2);
}

int switch_usr(game_t *infos)
{
    struct sigaction sig1;
    struct sigaction sig2;

    init_sig(&sig1, handler_player1, true);
    init_sig(&sig2, handler_player2, false);
    sig1.sa_sigaction = get_sig_pid;
    global_sig = 0;
    if (infos->player == 1)
        begin_usr1(sig1, sig2, infos);
    else {
        kill(infos->enemy_pid, SIGUSR1);
        sigaction(SIGUSR2, &sig2, NULL);
        usleep(100000);
        if (!global_sig)
            return (84);
    }
    return (0);
}

int print_beginning(players_t *my_map, players_t *enemy_map, game_t *infos)
{
    my_putstr("my_pid: ");
    my_put_nbr(infos->my_pid);
    my_putchar('\n');
    if (switch_usr(infos) == 84)
        return (84);
    if (infos->player == 1)
        my_putstr("enemy connected\n\n");
    print_map(my_map);
    print_enemy_map(enemy_map);
    return (0);
}
