/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** path.c
*/

#include "../include/my.h"
#include "../include/minishell.h"

int get_size_array(char **str_line)
{
    int len = 0;

    for (; str_line[len] != NULL; ++len);
    return (len);
}

void get_line(env_t *env_l)
{
    size_t n = 0;
    char *line = NULL;

    if (getline(&line, &n, stdin) == -1)
        exit(0);
    line[my_strlen(line) + 1] = '\0';
    env_l->str_line = my_str_to_word_array(line);
    env_l->str_size = get_size_array(env_l->str_line);
    add_cmd_history(*env_l);
}

int find_line_env(char *str, char **env)
{
    int i = 0;
    int len = my_strlen(str);

    while (my_strncmp(str, env[i], len) != 0) {
        ++i;
        if (env[i] == NULL)
            return (-1);
    }
    return (i);
}

char *have_permission(char *cmd)
{
    if (access(cmd, F_OK) == -1) {
        my_puterorr(cmd);
        my_puterorr(": Command not found.\n");
        return (NULL);
    }
    if (!is_regular_file(cmd) || access(cmd, X_OK) == -1) {
        my_puterorr(cmd);
        my_puterorr(": Permission denied.\n");
        return (NULL);
    }
    if (access(cmd, X_OK) == 0 || check_builtins(cmd))
        return (cmd);
    return (NULL);
}

char *get_path(env_t env)
{
    int line_path = find_line_env("PATH=", env.env);
    char *all_path = NULL;
    char *str_path = NULL;
    char *cmd = env.str_line[0];

    all_path = my_strdup(line_path != -1 ?
    env.env[line_path] : env.backup.path);
    str_path = str_path = strtok(all_path , ":");
    while (str_path != NULL) {
        str_path = my_strcat(str_path , "/");
        str_path = my_strcat(str_path , cmd);
        if (access(str_path, X_OK) == 0)
            return (str_path);
        str_path = strtok(NULL, ":");
    }
    return (have_permission(cmd));
}
