/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swaps content of two integers
*/

void my_swap (int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
