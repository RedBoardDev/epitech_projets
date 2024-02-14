/*
** EPITECH PROJECT, 2021
** 104intersection
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>

    #define square(a)  (a)*(a)

typedef struct point_s {
    int x;
    int y;
    int z;
} point_t;

typedef struct vector_s {
    int x;
    int y;
    int z;
    int t;
} vector_t;

typedef struct quadratic_equation_s {
    float a;
    float b;
    float c;
} quadratic_equation_t;

typedef struct resultat_eq_s {
    int nbr_solutions;
    float discriminant;
    float x1;
    float x2;
    float x;
} resultat_eq_t;

void print_help();
resultat_eq_t calculate_eq(quadratic_equation_t *eq);
resultat_eq_t funct_sphere(int radius, vector_t *vect, point_t *point);
resultat_eq_t funct_cylinder(int radius, vector_t *vect, point_t *point);
resultat_eq_t funct_cone(int delta, vector_t *vect, point_t *point);

#endif
