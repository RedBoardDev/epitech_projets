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
int my_putstr(char const *str);
int my_atoi(char const *src);
int isnum(char c);
int isparenthesis(char c);
int isope(char c);
int isletter(char c);

#endif /* MY_H_ */
