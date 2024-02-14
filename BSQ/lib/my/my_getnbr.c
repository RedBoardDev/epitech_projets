/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** returns a number
*/

#include "my.h"

int my_getnbr(const char *str)
{
    int i = 0;
    int x = 0;
    int sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        str[i] == '-' ? sign *= (-1) : x;
        i++;
    }
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            x *= 10;
            x += str[i] - '0';
        } else
            return x * sign;
        i++;
    }
    return (x * sign);
}
