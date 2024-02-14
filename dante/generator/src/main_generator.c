/*
** EPITECH PROJECT, 2021
** dante
** File description:
** main.c generator
*/

#include "../include/generator.h"
#include "../include/struct.h"
#include <time.h>

int main(int ac, char **av)
{
    time_t time_buff;

    srand((unsigned)time(&time_buff));
    if (ac != 3 && ac != 4)
        return (84);
    if (ac == 4 && !strcmp(av[3], "perfect"))
        generator((vector_t){atoi(av[1]), atoi(av[2])}, true);
    else
        generator((vector_t){atoi(av[1]), atoi(av[2])}, false);
    return (0);
}
