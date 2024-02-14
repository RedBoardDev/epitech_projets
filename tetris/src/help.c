/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-tetris-martin.d-herouville
** File description:
** help.c
*/

#include "../include/tetris.h"

int get_size_file(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return (stats.st_size);
}

int print_help(void)
{
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;
    int size = get_size_file("help.txt");

    fd = open("help.txt", O_RDONLY);
    if (fd == -1)
        exit(84);
    buffer = malloc(sizeof(char *) * size + 1);
    buffer[size] = '\0';
    rd = read(fd, buffer, size);
    if (rd == -1)
        exit(84);
    close(fd);
    write(1, buffer, size);
    free(buffer);
    return (1);
}
