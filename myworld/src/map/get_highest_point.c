/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** get_highest_point.c
*/


#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

int get_highest_point(int a, int b, int c, int d)
{
    if (a >= b && a >= c && a >= d)
        return (a);
    if (b >= a && b >= c && b >= d)
        return (b);
    if (c >= a && c >= b && c >= d)
        return (c);
    if (d >= a && d >= b && d >= c)
        return (d);
    return (-1);
}
