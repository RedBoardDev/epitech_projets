/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** prompt.c
*/

#include "../include/my.h"
#include "../include/minishell.h"

void my_prompt(char **env, int red)
{
    char *user = env[find_line_env("USER=", env)] + 5;
    char *pwd = get_current_path();
    int r = 0;

    for (int i = 0; pwd[i]; ++i)
        r = pwd[i] == '/' ? i : r;
    if (red < 1) {
        write(1, "\e[32m", 5);
        my_putstr("√|");
    } else {
        write(1, "\e[31m", 5);
        my_putstr("✗|");
    }
    write(1, "\033[0;36m", 8);
    my_putstr(user);
    my_putstr(" ");
    write(1, "\e[96m", 5);
    my_putstr(pwd + r + 1);
    write(1, "\33[0m", 4);
    my_putstr(": ");
}
