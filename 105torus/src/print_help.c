/*
** EPITECH PROJECT, 2021
** B-MAT-100-MLH-1-1-105torus-martin.d-herouville
** File description:
** print_help.c
*/

#include "../include/torus.h"
void print_help(){printf("USAGE\n    ./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n   opt       method option:\n                 1 for the bisection method\n                 2 for Newton’s method\n                 3 for the secant method\n   a[0-4]    coefficients of the equation\n   n         precision (the application of the polynomial to the solution should\n             be smaller than 10ˆ-n\n");}