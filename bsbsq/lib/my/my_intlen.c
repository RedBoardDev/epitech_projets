/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-bsbsq-thomas.ott
** File description:
** my_intlen.c
*/

#include "my.h"

int intlen(int i, int count)
{
    return (i / 10 > 0 ? intlen(i / 10, count += 1) : count + 1);
}