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

char **my_arraydup(char **src);
int my_strlen(char const *str);
void my_freearray(char **array);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);

#endif
