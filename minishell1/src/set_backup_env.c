/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** set_backup_env.c
*/

#include "../include/my.h"
#include "../include/minishell.h"

backup_t set_backup_env(char **env)
{
    backup_t backup;

    backup.home = env[find_line_env("HOME=", env)];
    backup.oldpath = env[find_line_env("OLDPWD=", env)];
    backup.path = env[find_line_env("PATH=", env)];
    backup.pwd = env[find_line_env("PWD=", env)];
    return (backup);
}
