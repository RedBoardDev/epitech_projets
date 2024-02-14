/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday09-thomas.ott
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int check_is_nbr(const char *str);
int my_getnbr(const char *str);
int my_putstr(char const *str);
void my_putchar(char c);

#endif
