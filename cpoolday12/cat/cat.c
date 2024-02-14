/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday12-thomas.ott
** File description:
** cat.c
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd;
    int sze = 30000;
    char buffer[30000];

    if (argc == 1) {
       while (sze = read(STDIN_FILENO, buffer, 30000))
            write(1, buffer, sze);
    }
    for (int i = 1; argc > i; ++i) {
        sze = 30000;
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
            return (84);

        while (sze == 30000) {
            sze = read(fd, buffer, 30000);
            write(1, buffer, sze);
        }
    }
    return 0;
}
