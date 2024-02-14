/*
** EPITECH PROJECT, 2021
** my_put_number.c
** File description:
** Displays the number given as parameter
*/

#include "../include/my.h"

int my_put_nbr_2(long nb, int count)
{
    int result = 0;
    long nb2 = nb;

    result = nb2 % 10;
    nb2 = nb2 / 10;
    if (nb2 > 0) {
        count += my_put_nbr_2(nb2, count);
    }
    count += my_putchar(result + 48);
    return (count);
}