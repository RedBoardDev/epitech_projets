/*
** EPITECH PROJECT, 2021
** MY_IS_PRIME
** File description:
** returns 1 if the number is prime or 0
*/

int check_prime_p(int nb)
{
    int i;

    for (i = 2; i <= nb / 2; ++i) {
        return ((nb % i == 0) ? 0 : 1);
    }
}

int my_find_prime_sup(int nb)
{
    int resultat;

    resultat = check_prime_p(nb);
    while (resultat == 0) {
        nb = nb + 1;
        resultat = check_prime_p(nb);
    }
    return (nb);
}
