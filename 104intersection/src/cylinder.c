/*
** EPITECH PROJECT, 2021
** B-MAT-100-MLH-1-1-104intersection-thomas.ott
** File description:
** cylinder.c
*/

#include "../include/struct.h"

resultat_eq_t funct_cylinder(int radius, vector_t *vect, point_t *point)
{
    quadratic_equation_t eq;

    eq.a = (square(vect->x) + square(vect->y));
    eq.b = 2 * ((point->x * vect->x) + (point->y * vect->y));
    eq.c = square(point->x) + square(point->y) - square(radius);
    return (calculate_eq(&eq));
}
