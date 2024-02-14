/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-bsminishell1-thomas.ott
** File description:
** minishell1.c
*/

#include "../include/my.h"

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg ++;
    }
}

int main(int argc , char **argv , char **env)
{
    char **str;
    // my_show_word_array(env);
    // execve("/bin/ls", argv, env);
    str = my_str_to_word_array(argv[1]);
    print_arg(str);
    return (0);
}