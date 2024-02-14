/*
** EPITECH PROJECT, 2021
** MY_IS_PRIME
** File description:
** returns 1 if the number is prime or 0
*/

int my_is_prime(int nb)
{
    for (int i = 2; i <= nb / 2; ++i)
        return (nb % i == 0) ? "false" : "true";
    return "false";
}
