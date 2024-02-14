/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** pushswap.c
*/

#include "../include/my.h"
#include "../include/pushswap.h"

int parse_list(list_t *list, smaller_t *smaller)
{
    list_t *it = list->next;
    int bool = 1;
    int size = 0;
    int prev = it->data;

    smaller->nbr = it->data;
    for (; it != list; it = it->next, ++size) {
        if (prev > it->data)
            bool = 0;
        if (smaller->nbr > it->data) {
            smaller->nbr = it->data;
            smaller->index = size;
        }
        prev = it->data;
    }
    list->size = size - 1;
    return (bool);
}

int check_pos_smaller_number(smaller_t *smaller, int size)
{
    int half = size / 2;
    if (smaller->index + 1 > half)
        return (1);
    else
        return (0);
}

int get_smaller(smaller_t *smaller, list_t *list_a, list_t *list_b,
int first_space)
{
    if (check_pos_smaller_number(smaller, list_a->size)) {
        while (get_first_node(list_a)->data != smaller->nbr) {
            my_rra(list_a, first_space);
            first_space = 1;
        }
    } else {
        while (get_first_node(list_a)->data != smaller->nbr) {
            my_ra(list_a, first_space);
            first_space = 1;
        }
    }
    return (first_space);
}

int push_swap(int argc, char const **argv)
{
    list_t *list_a = init_root_list();
    list_t *list_b = init_root_list();
    smaller_t smaller;
    int first_space = 0;

    for (int i = 1; i < argc; ++i) {
        if  (!check_is_nbr(argv[i]))
            add_end_list(list_a, my_getnbr(argv[i]));
        else
            return (84);
    }
    while (!parse_list(list_a, &smaller)) {
        first_space = get_smaller(&smaller, list_a, list_b, first_space);
        my_pb(list_a, list_b, first_space);
        first_space = 1;
    }
    while (list_b->next != list_b) {
        my_pa(list_a, list_b, first_space);
        first_space = 1;
    }
    my_putchar('\n');
    return (0);
}
