/*
** EPITECH PROJECT, 2021
** 104intersection
** File description:
** main.c
*/

#include "../include/struct.h"
#include <string.h>

resultat_eq_t calculate_eq(quadratic_equation_t *eq)
{
    resultat_eq_t res;
    res.discriminant = (eq->b * eq->b) - (4 * eq->a * eq->c);

    if (res.discriminant > 0) {
        res.nbr_solutions = 2;
        res.x1 = (-eq->b + sqrt(res.discriminant)) / (2 * eq->a);
        res.x2 = (-eq->b - sqrt(res.discriminant)) / (2 * eq->a);
        printf("2 intersection points:\n");
    } else if (res.discriminant == 0) {
        res.nbr_solutions = 1;
        res.x = (-eq->b / (2 * eq->a));
        printf("1 intersection point:\n");
    } else if (res.discriminant < 0) {
        res.nbr_solutions = 0;
        printf("No intersection point.\n");
        exit(0);
    }
    return (res);
}

int switch_surface(int nb, int radius, vector_t *vect, point_t *point)
{
    resultat_eq_t res;

    if (nb > 3 || nb < 1)
        exit(84);
    switch (nb)
    {
    case 1:
        printf("Sphere of radius %d\n", radius);
        printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", point->x, point->y, point->z, vect->x, vect->y, vect->z);
        res = funct_sphere(radius, vect, point);
        break;
    case 2:
        printf("Cylinder of radius %d\n", radius);
        printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", point->x, point->y, point->z, vect->x, vect->y, vect->z);
        res = funct_cylinder(radius, vect, point);
        break;
    case 3:
        if (radius < 0 || radius > 90)
            exit(84);
        printf("Cone with a %d degree angle\n", radius);
        printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", point->x, point->y, point->z, vect->x, vect->y, vect->z);
        res = funct_cone(radius, vect, point);
        break;
    default:
        exit (84);
        break;
    }
    if (res.nbr_solutions == 2) {
        printf("(%.3f, %.3f, %.3f)\n", point->x + res.x1 * vect->x, point->y + res.x1 * vect->y, point->z + res.x1 * vect->z);
        printf("(%.3f, %.3f, %.3f)\n", point->x + res.x2 * vect->x, point->y + res.x2 * vect->y, point->z + res.x2 * vect->z);
    } else if (res.nbr_solutions == 1) {
        printf("(%.3f, %.3f, %.3f)\n", point->x + res.x * vect->x, point->y + res.x * vect->y, point->z + res.x * vect->z);
    }
}

int isNumber(char *text)
{
    int j;

    j = strlen(text);
    while(j--) {
        if(text[j] >= '0' && text[j] <= '9' || (j == 0 && text[j] == '-'))
            continue;
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    vector_t vect;
    point_t point;

    if (ac < 2)
        exit(84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        print_help();
    if (ac != 9)
        exit(84);
    for (int i = 1; i < 9; ++i) {
        if (!isNumber(av[i]))
            exit(84);
    }
    point.x = atoi(av[2]);
    point.y = atoi(av[3]);
    point.z = atoi(av[4]);
    vect.x = atoi(av[5]);
    vect.y = atoi(av[6]);
    vect.z = atoi(av[7]);
    int angle = atoi(av[8]);
    switch_surface(atoi(av[1]), atoi(av[8]), &vect, &point);
    return (0);
}
