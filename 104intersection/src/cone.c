/*
** EPITECH PROJECT, 2021
** B-MAT-100-MLH-1-1-104intersection-thomas.ott
** File description:
** cone.c
*/

#include "../include/struct.h"

resultat_eq_t funct_cone(int delta, vector_t *vect, point_t *point)
{
    quadratic_equation_t eq;
    float angle = 90 - delta;

    angle = (angle * 3.14159265358979323846264338327950288419716939937510) / 180;
    eq.a = square(vect->x) + square(vect->y) - (square(vect->z) / (square(tan(angle))));
    eq.b = (2 * point->x * vect->x) + (2 * point->y * vect->y) - (2 * (point->z * vect->z) / (square(tan(angle))));
    eq.c = square(point->x) + square(point->y) - square(point->z) / (square(tan(angle)));
    return (calculate_eq(&eq));
}
