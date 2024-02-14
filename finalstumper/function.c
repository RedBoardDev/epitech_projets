/*
** EPITECH PROJECT, 2021
** function
** File description:
** function lib
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        if (nb * (-1) >= 10) {
            nb = (nb / 10) * (-1);
        } else
            nb = nb * (-1);
        my_putchar('-');
    }
    if  (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_putchar(nb % 10 + '0');
        } else
            my_putchar(nb + '0');  
    }
}
