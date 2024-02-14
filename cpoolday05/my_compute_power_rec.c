/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_REC
** File description:
** returns argument raised to the power p with recursive
*/

int my_compute_power_rec( int nb, int p)
{
    int result;

    result = 1;
    if (p < 0) {
        return  0;
    } else if (0 == p) {
        return result;
    }
    return  nb *= my_compute_power_rec(nb, --p);
}
