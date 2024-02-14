/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** displays the number given as a parameter c:
*/

void print_final(int bool)
{
    if (bool != 456789) {
        my_putchar(bool + '0');
    }
}

int my_put_nbr(int nb)
{
    int bool;

    bool = 456789;
    if (nb < 0) {
        if (nb * (-1) >= 10) {
            bool = nb%10*(-1);
            nb = (nb/10) * (-1);
        } else
            nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb/10);
            my_putchar(nb%10 + '0');
        } else
            my_putchar(nb + '0');
        print_final(bool);
    }
    return   (0);
}