/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** env.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

void my_show_env(env_t *env_l)
{
    my_show_word_array(env_l->env);
}

int check_size_arg_env(int str_size, char **env)
{
    if (str_size < 2) {
        my_show_word_array(env);
        return (1);
    } else if (str_size > 3) {
        my_puterorr("setenv: Too many arguments.\n");
        return (1);
    }
    return (0);
}

char **remove_line_env(int line, char **env)
{
    int size = 0;
    int size_2 = 0;
    char **backup = my_arraydup(env);

    while (env[size++]);
    free(env);
    env = malloc(sizeof(char *) * (size));
    size = 0;
    size_2 = 0;
    line == 0 ? ++size_2 : 0;
    while (backup[size_2]) {
        env[size] = my_strdup(backup[size_2]);
        ++size;
        ++size_2;
        size_2 == line ? ++size_2 : 0;
    }
    env[size] = NULL;
    return (env);
}

void my_unsetenv(env_t *env_l)
{
    int line = 0;
    char *arg = "=";

    if (env_l->str_size < 2) {
        my_puterorr("unsetenv: Too few arguments.\n");
        return;
    }
    arg = my_strcat(env_l->str_line[1], arg);
    line = find_line_env(arg, env_l->env);
    if (line == -1)
        return;
    env_l->env = remove_line_env(line, env_l->env);
}
