/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int  my_compute_square_root(int nb)
{
    int i;

    if (nb < 0) {
        return (0);
    }
    if (nb == 1) {
        return (1);
    }
    for (i = 1; i <= nb / 2; ++i) {
        if (i * i == nb) {
            return (i);
        }
    }
    return (0);
}
