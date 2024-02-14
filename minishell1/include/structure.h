/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** structure.h
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

typedef struct backup_s {
    char *oldpath;
    char *home;
    char *pwd;
    char *path;
} backup_t;

typedef struct env_s {
    backup_t backup;
    char **env;
    char **str_line;
    int str_size;
} env_t;

#endif
