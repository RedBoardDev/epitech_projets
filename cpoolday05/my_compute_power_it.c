/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_IT
** File description:
** returns argument raised to the power p
*/

int my_compute_power_it( int nb, int p)
{
    int result;

    result = 1;
    if  (p < 0) {
        return  0;
    }
    while   (p >= 1) {
        result *= nb;
        --p;
    }
    return   result;
}
