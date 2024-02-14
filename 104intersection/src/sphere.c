/*
** EPITECH PROJECT, 2021
** B-MAT-100-MLH-1-1-104intersection-thomas.ott
** File description:
** sphere.c
*/

#include "../include/struct.h"

resultat_eq_t funct_sphere(int radius, vector_t *vect, point_t *point)
{
    quadratic_equation_t eq;

    eq.a = (square(vect->x) + square(vect->y) + square(vect->z));
    eq.b = ((2 * point->x * vect->x) + (2 * point->y * vect->y) + (2 * point->z * vect->z));
    eq.c = square(point->x) + square(point->y) + square(point->z) - square(radius);
    return (calculate_eq(&eq));
}
