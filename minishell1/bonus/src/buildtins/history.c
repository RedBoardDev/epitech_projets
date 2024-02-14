/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** history.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

void add_cmd_history(env_t env_l)
{
    int str_size = 0;
    char *home = my_strcat(env_l.backup.home, "/.mysh_history") + 5;
    int fd = open(home, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU | S_IWUSR);

    for (int i = 0; env_l.str_line[i] != NULL; ++i) {
        str_size = my_strlen(env_l.str_line[i]);
        write(fd, env_l.str_line[i], str_size);
        if (env_l.str_line[i + 1] != NULL)
            write(fd, " ", 1);
    }
    write(fd, "\n", 1);
    close(fd);
}

void builtin_history(env_t *env_l)
{
    struct stat stats;
    char *home = my_strcat(env_l->backup.home, "/.mysh_history") + 5;
    int fd = 0;
    char *buf;

    if (env_l->str_size > 1 && my_strcmp(env_l->str_line[1], "-c") == 0) {
        remove(home);
        return;
    }
    fd = open(home, O_RDONLY);
    stat(home, &stats);
    buf = malloc(sizeof(char) * stats.st_size);
    read(fd, buf, stats.st_size);
    write(1, buf, stats.st_size);
    free(buf);
}
