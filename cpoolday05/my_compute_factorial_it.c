/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_FACTORIAL_IT
** File description:
** Returns the factorial of the number
*/

int my_compute_factorial_it(int nb)
{
    int i;
    int f;

    f = 1;
    if(nb < 0 || nb >= 13) {
        return  (0);
    }
    if  (nb == 0 || nb == 1) {
        return  (1);
    }
    for (i = 1; i <= nb; i++) {
        f = f* i;
    }
    return f;
}
