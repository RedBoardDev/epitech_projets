/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-bsbsq-thomas.ott
** File description:
** utils_file.c
*/

#include "../include/my.h"
#include "../include/bsq.h"

int fs_open_file(char const *filepath)
{
    int file_int;

    file_int = open(filepath, O_RDONLY);
    if (file_int > 0) {
        my_putstr("SUCCESS\n");
        return (file_int);
    } else {
        my_putstr("FAILURE\n");
        return (file_int);
    }
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int file_int;

    file_int = read(fd, buffer, size);
    if (file_int == -1)
        my_putstr("read failed\n");
    else if (file_int == 0)
        my_putstr("read has nothing more to read\n");
    else if (file_int < size)
        my_putstr("read didn’t complete the entire buffer\n");
    else if (file_int == size)
        my_putstr("read completed the entire buffer\n");
}

