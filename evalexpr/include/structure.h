/*
** EPITECH PROJECT, 2021
** Structur.h
** File description:
** Structur
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

typedef struct linked_list_s {
    char data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct list_calcul_s {
    int data;
    struct list_calcul_s *next;
} list_calcul_t;

#endif
