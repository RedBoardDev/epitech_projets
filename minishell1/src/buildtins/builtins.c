/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** buildtins.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

static char const *flag[] = {"exit", "cd", "env", "setenv", "unsetenv"};
static const void (*funct[]) (env_t *) =
{builtin_exit, builtin_cd, my_show_env, my_set_env, my_unsetenv};

void builtin_exit(env_t *env_l)
{
    my_putstr("exit\n");
    exit(0);
}

void search_builtins(int i_buildtins, env_t *env_l)
{
    (*funct[i_buildtins - 1])(env_l);
}

int check_builtins(char *cmd)
{
    int i = 0;

    while (flag[i] != NULL) {
        if (my_strcmp(cmd, flag[i]) == 0)
            return (i + 1);
        ++i;
    }
    return (0);
}
