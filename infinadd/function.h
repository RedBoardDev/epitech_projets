/*
** EPITECH PROJECT, 2021
** B-CPE-101-MLH-1-1-infinadd-thomas.ott
** File description:
** function.h
*/

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char *add_calcul(char *av1, char *av2);
char *my_memset(char *buffer, char *av, int size);
int compare_len(int av1, int av2);
char *sub_calcul(char *av1, char *av2, int bool);
void my_swap_char(char *a, char *b);
int compare_len_sub(char *av1, char *av2);
int putstr_number(char *str);

#endif
