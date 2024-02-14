/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int i;

    if (nb <= 1) {
        return (0);
    }
    for (i = 2; i <= nb / 2; ++i) {
        if (nb % i == 0 && i != nb) {
            return (0);
        }
    }
    return (1);
}
