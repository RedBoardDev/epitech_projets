/*
** EPITECH PROJECT, 2021
** 105torus
** File description:
** torus.h
*/

#ifndef TORUS_H
    #define TORUS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #define square2(a)  (a)*(a)
    #define square3(a)  (a)*(a)*(a)
    #define square4(a)  (a)*(a)*(a)*(a)

typedef struct args_s {
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
} args_t;

typedef struct def_f_s {
    int a;
    int b;
    int c;
    int d;
} def_f_t;

typedef struct interval_s {
    float a;
    float b;
} interval_t;

void print_help();

#endif
