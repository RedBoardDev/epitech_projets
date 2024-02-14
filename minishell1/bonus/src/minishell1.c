/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-bsminishell1-thomas.ott
** File description:
** minishell1.c
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include <errno.h>

void check_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            my_puterorr("Segmentation fault");
        if (WTERMSIG(status) == SIGFPE)
            my_puterorr("Floating exception");
        if (WTERMSIG(status) == SIGQUIT)
            my_puterorr("Quit");
        if (WTERMSIG(status) == SIGTERM)
            my_puterorr("Terminated");
        if (WTERMSIG(status) == SIGKILL)
            my_puterorr("Killed");
        if (WTERMSIG(status) == SIGBUS)
            my_puterorr("Bus error");
        if (WCOREDUMP(status))
            my_puterorr(" (core dumped)");
        my_puterorr("\n");
    }
}

env_t set_executor(env_t *env_l)
{
    char *path = get_path(*env_l);
    pid_t fork_pid;
    int wstatus;
    int i_buildtins = check_builtins(env_l->str_line[0]);

    path != NULL ? (env_l->oldcmd = path) : 0;
    if (path != NULL && !i_buildtins) {
        fork_pid = fork();
        if (fork_pid == 0)
            execve(path, env_l->str_line, env_l->env);
        if (errno == ENOEXEC) {
            my_puterorr(env_l->str_line[0]);
            my_puterorr(": Exec format error. Wrong Architecture.\n");
            exit(0);
        }
        if (waitpid(fork_pid, &wstatus, 0) == -1)
            return (*env_l);
        check_status(wstatus);
    } else if (i_buildtins)
        search_builtins(i_buildtins, env_l);
    return (*env_l);
}

void manage_signal(int sig)
{
    pid_t fork_pid = fork();
    int wstatus;

    if (sig == SIGSEGV)
        exit(0);
    if (fork_pid == 0)
        exit(0);
    if (waitpid(fork_pid, &wstatus, 0) == -1)
        exit(0);
}

int minishell(int argc , char **argv , char **env_s)
{
    char **str_line;
    env_t env_l;
    int r = -2;

    env_l.env = my_arraydup(env_s);
    env_l.str_line = NULL;
    env_l.oldcmd = env_l.env[find_line_env("_=", env_l.env)];
    find_line_env("PATH=", env_l.env) == -1 ? exit(84) : 0;
    env_l.backup = set_backup_env(env_s);
    signal(SIGINT, manage_signal);
    while (1) {
        my_prompt(env_l.env, r);
        get_line(&env_l);
        if (env_l.str_size > 0) {
            env_l = set_executor(&env_l);
            my_set_env_old(&env_l, my_strcat("_=", env_l.oldcmd), "_=");
        }
        free(env_l.str_line);
        ++r;
    }
    free(env_l.env);
    free(env_l.str_line);
}
