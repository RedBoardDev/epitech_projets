/*
** EPITECH PROJECT, 2021
** PROJET-thomas.ott
** File description:
** projet.h
*/

#ifndef PROJET_H_
    #define PROJET_H_

    #include <sys/types.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <stdlib.h>
    #include <signal.h>
    #include "structure.h"

int minishell(int argc , char **argv , char **env);
void search_builtins(int i_buildtins, env_t *env_l);
char *get_path(env_t env);
int check_builtins(char *cmd);
void builtin_cd(env_t *env_l);
void my_set_env(env_t *env_l);
void my_unsetenv(env_t *env_l);
void my_show_env(env_t *env_l);
void builtin_exit(env_t *env_l);
int find_line_env(char *str, char **env);
backup_t set_backup_env(char **env);
void get_line(env_t *env_l);
void my_set_env_oldpath(env_t *env_l, char *str);
int check_size_arg_env(int str_size, char **env);
void my_prompt(void);
int check_setenv_arg(char *str);
char **remove_line_env(int line, char **env);
void check_status(int pid);
int is_regular_file(char *path);
int error_handling_cd(char *str);
void builtin_exit(env_t *env_l);
int get_size_array(char **str_line);
char *have_permission(char *cmd);

#endif
