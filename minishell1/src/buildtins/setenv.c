/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** setenv.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

int check_setenv_arg(char *str)
{
    if (!isletter(str[0])) {
        my_puterorr("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isletter(str[i]) && !isnum(str[i])) {
            my_puterorr("setenv: Variable name must");
            my_puterorr(" contain alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

char **add_line_env(char *arg, char **str_line, char **env, int str_size)
{
    int size = 0;
    char **backup = my_arraydup(env);

    while (env[size++]);
    free(env);
    env = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while (backup[size]) {
        env[size] = my_strdup(backup[size]);
        ++size;
    }
    if (str_size == 3)
        arg = my_strcat(arg, str_line[2]);
    env[size] = arg;
    env[size + 1] = NULL;
    return (env);
}

void my_set_env(env_t *env_l)
{
    int line = 0;
    char *arg = "=";

    if (check_size_arg_env(env_l->str_size, env_l->env))
        return;
    if (check_setenv_arg(env_l->str_line[1]))
        return;
    arg = my_strcat(env_l->str_line[1], arg);
    line = find_line_env(arg, env_l->env);
    if (line == -1) {
        env_l->env =
        add_line_env(arg, env_l->str_line, env_l->env, env_l->str_size);
        return;
    }
    env_l->str_size == 3 ? (arg = my_strcat(arg, env_l->str_line[2])) : 0;
    free(env_l->env[line]);
    env_l->env[line] = malloc(sizeof(char *) * (my_strlen(arg) + 1));
    env_l->env[line] = arg;
}

char **add_line_env_oldpath(char *str, char **env)
{
    int size = 0;
    char **backup = my_arraydup(env);

    while (env[size++]);
    free(env);
    env = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while (backup[size]) {
        env[size] = my_strdup(backup[size]);
        ++size;
    }
    env[size] = str;
    env[size + 1] = NULL;
    return (env);
}

void my_set_env_oldpath(env_t *env_l, char *str)
{
    int line = find_line_env("OLDPWD=", env_l->env);

    if (line == -1) {
        env_l->env = add_line_env_oldpath(str, env_l->env);
        return;
    }
    env_l->env[line] = malloc(sizeof(char *) * (my_strlen(str) + 1));
    env_l->env[line] = str;
}
