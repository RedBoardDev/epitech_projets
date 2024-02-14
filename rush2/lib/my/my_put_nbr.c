/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my_put_nbr
*/

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return 0;
}
