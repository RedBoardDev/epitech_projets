#include "../include/torus.h"

int isNumber(char *text)
{
    int j;

    j = strlen(text);
    while(j--) {
        if(text[j] >= '0' && text[j] <= '9' || (j == 0 && text[j] == '-'))
            continue;
        return 0;
    }
    return 1;
}

int error_handling(int ac, char **av)
{
    if (ac < 2)
        exit(84);
    // if (av[1][0] == '-' && av[1][1] == 'h')
    //     print_help();
    if (ac != 8)
        exit(84);
    for (int i = 1; i < 8; ++i) {
        if (!isNumber(av[i]))
            exit(84);
    }
}

float calc_pouissance(int arg, int pouissance)
{
    float res = arg;
    if (pouissance > 0)
        for (int i = 0; i < pouissance - 1; ++i)
            res *= arg;
    else
        for (int i = 0; i > pouissance - 1; --i)
            res /= arg;
    return (res);
}

float calc_func(def_f_t f, int x)
{
    // return (args->a0 * x + args->a1 * x + args->a2 * x + args->a3 * x + args->a4 * x);
    return (f.a * (square4(x)) + f.b * (square3(x)) + f.c * (square2(x)) + f.d);
}

float calc_func_prime(args_t *args, int x)
{
    return (4 * args->a4 * x + 3 * args->a3 * x + 2 * args->a2 * x + args->a1 * x);
}

float bisection(def_f_t f, interval_t interval)
{
    float midpoint = (interval.a + interval.b) / 2;
    interval_t buff_inter = {interval.a, interval.b};
    float fa = calc_func(f, buff_inter.a);
    float fc = calc_func(f, midpoint);

    for (; fc >= 0.0001; midpoint = (buff_inter.a + buff_inter.b) / 2) {
        fa = calc_func(f, buff_inter.a);
        fc = calc_func(f, midpoint);
        if (fa * fc < 0)
            buff_inter.b = midpoint;
        else
            buff_inter.a = midpoint;
        printf("midpoint = %f\n", midpoint);
    }
    return (midpoint);
}

int main(int ac, char **av)
{
    return (84);
    // printf("calc = %f\n", calc_pouissance(10, -3));
    // exit(0);
    // error_handling(ac, av);
    // args_t args = {atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5])};
    args_t args = {0, 1, 6, -5, 1};
    def_f_t func = {atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4])};
    interval_t interval = {atoi(av[5]), atoi(av[6])};

    // printf("%d\n", calc_func(&args, atoi(av[6])));
    // printf("%d\n", calc_func_prime(&args, atoi(av[6])));
    // float new = bisection(func, interval);
    // printf("res = %f\n", new);
}
