/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** builtin_cd.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

int is_regular_file(char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return (S_ISREG(path_stat.st_mode));
}

int error_handling_cd(char *str)
{
    int file = is_regular_file(str);

    my_puterorr(str);
    if (file)
        my_puterorr(": Not a directory.\n");
    else
        my_puterorr(": No such file or directory.\n");
    return (1);
}

int cd_with_args(env_t *env_l)
{
    if (my_strcmp(env_l->str_line[1], ".") == 0)
        return (1);
    if (my_strcmp(env_l->str_line[1], "..") == 0) {
        chdir("..");
    } else if (my_strcmp(env_l->str_line[1], "-") == 0) {
        if (chdir(env_l->backup.oldpath) == -1) {
            perror(env_l->str_line[1]);
            return (1);
        }
    } else
        return (chdir(env_l->str_line[1]) == -1 ?
        error_handling_cd(env_l->str_line[1]) : 0);
    return (0);
}

char *get_current_path(void)
{
    size_t n = 0;
    char *buf = NULL;

    return (getcwd(buf, n));
}

void builtin_cd(env_t *env_l)
{
    char *current_path = get_current_path();
    int oldpath_bool = 0;

    if (env_l->str_size > 2)
        my_puterorr("cd: Too many arguments.\n");
    else if (env_l->str_size == 1) {
        chdir(env_l->backup.home + 5);
        oldpath_bool = 0;
    } else
        oldpath_bool = cd_with_args(env_l);
    if (oldpath_bool == 0) {
        my_set_env_oldpath(env_l, my_strcat("OLDPWD=", current_path));
        env_l->backup.oldpath = my_strdup(current_path);
    }
    free(current_path);
}
