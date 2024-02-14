/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
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

int isnum(char c);
char *my_itoa(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
#endif
