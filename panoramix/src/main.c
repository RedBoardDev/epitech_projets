/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** main.c
*/

#include <stdio.h>
#include "../include/panoramix.h"

int print_help_when_error(void)
{
    fprintf(stderr, "USAGE: ./panoramix <nb_villagers> <pot_size> ");
    fprintf(stderr, "<nb_fights> <nb_refills>\n");
    fprintf(stderr, "Values must be >0.\n");
    return 84;
}

int main(int argc, char const **argv)
{
    panoramix_t *panoramix = malloc(sizeof(panoramix_t));
    if (verify_arguments(argc, argv) == false)
        return print_help_when_error();
    fill_struct(panoramix, argv);
    return panoramix_fct(panoramix);
}
