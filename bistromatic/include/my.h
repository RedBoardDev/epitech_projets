/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday09-martin.d-herouville
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>

void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_atoi(char const *src);
void my_putchar_error(char c);
int my_putstr_error(char const *str);
char *my_revstr(char *str);

#endif /* MY_H_ */
