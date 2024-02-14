/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** pushswap.h
*/

#ifndef PUSHSWAP_H_
    #define PUSHSWAP_H_

typedef struct list_s {
    int data;
    int size;
    struct list_s *next;
    struct list_s *prev;
} list_t;

typedef struct smaller_s {
    int nbr;
    int index;
} smaller_t;

list_t *init_root_list(void);
void browse_list(list_t *list);
list_t *get_last_node(list_t *list);
list_t *get_second_node(list_t *list);
list_t *get_first_node(list_t *list);
void add_end_list(list_t *list, int nbr);
void add_beginning_list(list_t *list, int nbr);
void remove_element(list_t *list);
void remove_end_list(list_t *list);
void remove_beginning_list(list_t *list);
int my_sa(list_t *list_a, int first_space);
int my_ra(list_t *list_a, int first_space);
int my_rra(list_t *list_a, int first_space);
int my_pa(list_t *list_a, list_t *list_b, int first_space);
int my_pb(list_t *list_a, list_t *list_b, int first_space);
int push_swap(int argc, char const **argv);

#endif
