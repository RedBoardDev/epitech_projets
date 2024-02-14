/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_FACTORIAL_rec
** File description:
** Returns the factorial of the number with recursive
*/

int my_compute_factorial_rec(int nb)
{
    int f = 1;

    if  (nb < 0 || nb >= 13) {
        return  (0);
        }
     if  (nb == 0 || nb == 1) {
         return  (1);
     }
     return (nb * my_compute_factorial_rec(nb-1));
}
