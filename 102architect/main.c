/*
** EPITECH PROJECT, 2021
** 102architect
** File description:
** main.c
*/

#include "include/struct.h"
#include "include/my.h"

void init(matrice_t *matrice)
{
    matrice->case1 = 0;
    matrice->case2 = 0;
    matrice->case3 = 0;
    matrice->case4 = 0;
    matrice->case5 = 0;
    matrice->case6 = 0;
    matrice->case7 = 0;
    matrice->case8 = 0;
    matrice->case9 = 1;
}

void translation(matrice_t *matrice, int x, int y, int translation_x, int translation_y)
{
    printf("Translation along vector (%d, %d)\n", translation_x, translation_y);
    matrice->case1 += translation_y;
    matrice->case5 += translation_y;
    matrice->case3 += translation_x;
    matrice->case6 += translation_y;
}

void scaling(matrice_t *matrice, int x, int y, int scaling_x, int scaling_y)
{
    printf("Scaling by factors %d and %d\n", scaling_x, scaling_y);
    matrice->case1 += scaling_x;
    matrice->case5 += scaling_y;
}

void rotation(matrice_t *matrice, int x, int y, float angle)
{
    printf("Rotation by a %0.0f degree angle\n", angle);
    angle = angle * (3.14159 / 180);
    matrice->case1 += cos(angle);
    matrice->case2 += -sin(angle);
    matrice->case4 += sin(angle);
    matrice->case5 += cos(angle);
}

void reflexion(matrice_t *matrice, int x, int y, float angle)
{
    printf("Reflection over an axis with an inclination angle of %0.0f degrees\n", angle);
    angle = angle * (3.14159 / 180);
    matrice->case1 += cos(2 * angle);
    matrice->case2 += sin(2 * angle);
    matrice->case4 += sin(2 * angle);
    matrice->case5 += -cos(2 * angle);
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
    float x = 0;
    float y = 0;
    char arg;
    int rotation_angle = 0;
    int translation_x = 0;
    int translation_y = 0;
    int scaling_x = 0;
    int scaling_y = 0;
    int reflexion_angle = 0;
    matrice_t matrice;

    if (ac == 1 || ac <= 4)
        exit(84);
    switch (av[3][1]) {
    case 't':
        if (ac != 6 || isNumber(av[4]) != 1 || isNumber(av[5]) != 1)
            exit(84);
        break;
    case 'z':
        if (ac != 6 || isNumber(av[4]) != 1 || isNumber(av[5]) != 1)
            exit(84);
        break;
    case 'r':
        if (ac != 5 || isNumber(av[4]) != 1)
            exit(84);
        break;
    case 's':
        if (ac != 5|| isNumber(av[4]) != 1)
            exit(84);
        break;
    default:
        exit(84);
        break;
    }
    init(&matrice);
    for (int i = 1; i < ac; ++i) {
        x = atof(av[i]);
        ++i;
        y = atof(av[i]);
        ++i;
        if (av[i][0] == '-')
            arg = av[i][1];
        ++i;
        if (arg == 't') {
            translation_x = atof(av[i]);
            ++i;
            translation_y = atof(av[i]);
            ++i;
            translation(&matrice, x, y, translation_x, translation_y);
        } else if (arg == 'z') {
            scaling_x = atof(av[i]);
            ++i;
            scaling_y = atof(av[i]);
            ++i;
            scaling(&matrice, x, y, scaling_x, scaling_y);
        } else if (arg == 'r') {
            rotation_angle = atof(av[i]);
            ++i;
            rotation(&matrice, x, y, rotation_angle);
        } else if (arg == 's') {
            reflexion_angle = atof(av[i]);
            ++i;
            reflexion(&matrice, x, y, reflexion_angle);
        } else
            printf("Oui\n");
    }

    float new_x = (matrice.case1 * x) + (matrice.case2 * y) + (matrice.case3);
    float new_y = (matrice.case4 * x) + (matrice.case5 * y) + (matrice.case6);

    printf("%0.2f   %0.2f   %0.2f\n", matrice.case1, matrice.case2, matrice.case3);
    printf("%0.2f   %0.2f   %0.2f\n", matrice.case4, matrice.case5, matrice.case6);
    printf("%0.2f   %0.2f   %0.2f\n", matrice.case7, matrice.case8, matrice.case9);
    printf("(%0.2f, %0.2f) => (%0.2f, %0.2f)\n", x, y, new_x, new_y);
}
