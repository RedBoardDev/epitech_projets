/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** Boostrap BSQ
*/

#include "../include/my.h"

int fs_open_file(char const *filepath)
{
    int file_int;

    file_int = open(filepath, O_RDONLY);
    if (file_int > 0) {
        my_putstr("SUCCESS\n");
        return (file_int);
    } else {
        my_putstr("FAILURE\n");
        return (file_int);file_int = open(filepath, O_RDONLY);
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

void fs_cat_500_bytes(char const *filepath)
{
    char *buffer[500];
    int fd = open(filepath, O_RDONLY);
    int rd = read(fd, buffer, 500);
    write(1, buffer, 500);
}

int main (int agc, char **agv)
{
//    fs_understand_return_of_read(fs_open_file(agv[1]), agv[1], 30);
    fs_cat_500_bytes(agv[1]);
    return (0);
}
