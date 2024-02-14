/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_SQUARE_ROOT
** File description:
** returns the square root of the argument
*/

int my_compute_square_root(int nb)
{
    int result;
    int i;
    for (i = 1; result < nb; i++) {
        if (i > 32767 || i * i >= nb + 1) {
            return 0;
        }
        result = i * i;
    }
    return i - 1;
}
