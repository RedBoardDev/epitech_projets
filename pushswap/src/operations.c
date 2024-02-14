/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** operations.c
*/

#include "../include/pushswap.h"
#include "../include/my.h"

int my_pa(list_t *list_a, list_t *list_b, int first_space)
{
    if (get_first_node(list_b)) {
        add_beginning_list(list_a, get_first_node(list_b)->data);
        remove_beginning_list(list_b);
        first_space ? my_putstr(" pa") : my_putstr("pa");
    } else
        return (0);
    return (1);
}

int my_pb(list_t *list_a, list_t *list_b, int first_space)
{
    if (get_first_node(list_a)) {
        add_beginning_list(list_b, get_first_node(list_a)->data);
        remove_beginning_list(list_a);
        first_space ? my_putstr(" pb") : my_putstr("pb");
    } else
        return (0);
    return (1);
}

int my_sa(list_t *list_a, int first_space)
{
    int first = 0;
    int second = 0;

    if (list_a->next->next != list_a) {
        first = get_first_node(list_a)->data;
        second = get_second_node(list_a)->data;
        remove_beginning_list(list_a);
        remove_beginning_list(list_a);
        add_beginning_list(list_a, first);
        add_beginning_list(list_a, second);
        first_space ? my_putstr(" sa") : my_putstr("sa");
    } else
        return (0);
    return (1);
}

int my_ra(list_t *list_a, int first_space)
{
    int first = 0;

    if (list_a->next->next != list_a) {
        first = get_first_node(list_a)->data;
        remove_beginning_list(list_a);
        add_end_list(list_a, first);
        first_space ? my_putstr(" ra") : my_putstr("ra");
    } else
        return (0);
    return (1);
}

int my_rra(list_t *list_a, int first_space)
{
    int last = 0;

    if (list_a->next->next != list_a) {
        last = get_last_node(list_a)->data;
        remove_end_list(list_a);
        add_beginning_list(list_a, last);
        first_space ? my_putstr(" rra") : my_putstr("rra");
    } else
        return (0);
    return (1);
}
