/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void is_maj(char c, int key, int file)
{
    char tmp[1];

    if (c + key > 90)
        c -= 26;
    if (c + key < 65)
        c += 26;
    tmp[0] = c + key;
    if (write(file, tmp, 1) == -1)
        exit(84);
}

void is_min(char c, int key, int file)
{
    char tmp[1];

    if (c + key > 122)
        c -= 26;
    if (c + key < 97)
        c += 26;
    tmp[0] = c + key;
    if (write(file, tmp, 1) == -1)
        exit(84);
}

void start_decypher(char *string, int key)
{
    int file = open("crypt", O_CREAT | O_WRONLY,
S_IRUSR | S_IRGRP | S_IROTH);

    if (file == -1)
        exit(84);
    for (int i = 0; string[i]; ++i) {
        if (my_chara_is_alpha_maj(string[i]))
            is_maj(string[i], key, file);
        if (my_chara_is_alpha_min(string[i]))
            is_min(string[i], key, file);
        if (my_c_is_alpha(string[i]) == 0)
            write(file, string + i, 1) == -1 ? exit(84) : 0;
    }
    if (close(file) == -1)
        exit(84);
}
