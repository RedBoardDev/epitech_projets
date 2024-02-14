/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** backup_score.c
*/

#include "../include/struct.h"
#include "../include/tetris.h"

int get_nbr_custom(char *buff)
{
    int result = 0;

    if (buff[0] == '\0')
        return (0);
    for (int i = 0; isnum(buff[i]); ++i) {
        result *= 10;
        result += (buff[i] - 48);
    }
    return (result);
}

int get_backup(void)
{
    int fd = open("highest_score.txt", O_RDONLY);
    struct stat stat_buff;
    char *buff;

    stat("highest_score.txt", &stat_buff);
    buff = malloc(sizeof(char) * (stat_buff.st_size + 1));
    if (fd == -1 || read(fd, buff, stat_buff.st_size) == -1) {
        close(fd);
        return (0);
    }
    buff[stat_buff.st_size] = '\0';
    close(fd);
    return (get_nbr_custom(buff));
}

void put_backup(int nbr)
{
    int fd = open("highest_score.txt", O_WRONLY);
    char *buff;
    int nbr2 = nbr;
    int i = 0;

    if (fd == -1) {
        close(fd);
        printf("non\n");
        return;
    }
    for (; nbr2 > 0; ++i)
        nbr2 /= 10;
    buff = malloc(sizeof(char) * i);
    buff = my_itoa(nbr);
    write(fd, buff, i);
    close(fd);
}
