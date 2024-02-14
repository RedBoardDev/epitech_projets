/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game_wait.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

extern int global_sig;

void handler_receive(int sig)
{
    if (sig == SIGUSR1)
        ++global_sig;
    else
        global_sig *= 10;
}

int receive_signal(void)
{
    struct sigaction sig1;
    struct sigaction sig2;

    global_sig = 0;
    init_sig(&sig1, handler_receive, false);
    init_sig(&sig2, handler_receive, false);
    sigaction(SIGUSR1, &sig1, NULL);
    sigaction(SIGUSR2, &sig2, NULL);
    while (!(global_sig / 10))
        pause();
    return (global_sig);
}

bool check_hit(players_t *my_map, int letter, int number)
{
    my_putchar(letter + 64);
    my_put_nbr(number);
    if (isnum(my_map->map[number - 1][letter - 1])) {
        my_map->map[number - 1][letter - 1] = 'x';
        my_putstr(": hit\n");
        return (true);
    } else if (my_map->map[number - 1][letter - 1] == 'x') {
        my_putstr(": missed\n");
        return (false);
    } else {
        my_map->map[number - 1][letter - 1] = 'o';
        my_putstr(": missed\n");
        return (false);
    }
}

int wait(players_t *my_map, players_t *enemy_map, game_t *info)
{
    int letter;
    int number;

    my_putstr("\nwaiting for enemy's attack...\n");
    letter = receive_signal() / 10;
    number = receive_signal() / 10;
    usleep(10000);
    if (check_hit(my_map, letter, number))
        kill_ft(info->enemy_pid, 1);
    else
        kill_ft(info->enemy_pid, 2);
}
