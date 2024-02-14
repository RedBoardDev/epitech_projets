/*
** EPITECH PROJECT, 2021
** help
** File description:
** help.c
*/

#include "my.h"
#include <stdlib.h>
#include "sys/types.h"
#include "sys/stat.h"
#include <fcntl.h>
#include <unistd.h>

int get_size_file(char *path)
{
    int nbr = 0;

    struct stat stats;

    stat(path, &stats);
    nbr = stats.st_size;
    return (nbr);
}

char *get_file(char *path)
{
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;
    int size = get_size_file(path);

    fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(84);
    buffer = malloc(sizeof(char *) * size + 1);
    if (buffer == NULL)
        exit(84);
    buffer[size] = '\0';
    rd = read(fd, buffer, size);
    if (rd == -1)
        exit(84);
    close(fd);
    buffer[size] = '\0';
    return (buffer);
}
