/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** game.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

extern int global_sig;

int check_exist_position(char *buff)
{
    int i = 0;

    while (buff[i] == ' ')
        ++i;
    if (buff[i] < 'A' || buff[i] > 'H')
        return (1);
    ++i;
    while (buff[i] == ' ')
        ++i;
    if (buff[i] < 49 || buff[i] > 56)
        return (1);
    if (mystrlen_custom(buff) > 2)
        return (1);
    return (0);
}

void send_signal(char *str, game_t *info)
{
    int letter = str[0] - 64;
    int number = str[1] - '0';

    for (; letter > 0; --letter) {
        kill_ft(info->enemy_pid, 1);
    }
    kill_ft(info->enemy_pid, 2);
    for (; number > 0; --number)
        kill_ft(info->enemy_pid, 1);
    kill(info->enemy_pid, SIGUSR2);
}

int recieve_hit_summary(players_t *enemy_map, char *arg)
{
    struct sigaction sig1;
    struct sigaction sig2;

    global_sig = 0;
    init_sig(&sig1, handler_recieve_hit_summary, false);
    init_sig(&sig2, handler_recieve_hit_summary, false);
    sigaction(SIGUSR1, &sig1, NULL);
    sigaction(SIGUSR2, &sig2, NULL);
    while (!global_sig)
        pause();
    my_putstr(arg);
    if (global_sig == 2) {
        my_putstr(": hit\n");
        modify_map(enemy_map, true, arg);
    } else if (global_sig == 1) {
        my_putstr(": missed\n");
        modify_map(enemy_map, false, arg);
    }
}

char *modify_str(char *str)
{
    int i = 0;

    while (str[i] == ' ')
        ++i;
    *str = str[i];
    ++i;
    while (str[i] == ' ')
        ++i;
    str[1] = str[i];
    str[2] = '\0';
    return (str);
}

int play(players_t *my_map, players_t *enemy_map, game_t *info)
{
    bool good = false;
    char *str = NULL;
    size_t n = 0;

    while (!good) {
        my_putstr("\nattack: ");
        getline(&str, &n, stdin);
        if (check_exist_position(str))
            my_putstr("wrong position");
        else
            good = true;
    }
    modify_str(str);
    send_signal(str, info);
    recieve_hit_summary(enemy_map, str);
}
