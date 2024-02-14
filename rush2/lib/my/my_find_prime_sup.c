/*
** EPITECH PROJECT, 2021
** my_find_prime
** File description:
** my_find_prime
*/

int my_find_prime_sup(int nb)
{
    while (nb) {
        if (my_is_prime(nb) == 1) {
            return (nb);
        }
        nb += 1;
    }
}
