/*
** EPITECH PROJECT, 2021
** 101pong
** File description:
** main.c
*/

#include "include/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int velocity(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float x = x2 - x1;
    float y = y2 - y1;
    float z = z2 - z1;

    printf("The velocity vector of the ball is:\n");
    printf("(%0.2f, %0.2f, %0.2f)\n", x, y, z);
    return (0);
}

void coordinates(float x1, float y1, float z1, float x2, float y2, float z2, int n)
{
    float x = x2 + (x2 - x1) * n;
    float y = y2 + (y2 - y1) * n;
    float z = z2 + (z2 - z1) * n;

    printf("At time t + 4, ball coordinates will be:\n");
    printf("(%0.2f, %0.2f, %0.2f)\n", x, y, z);
}

void angle_calc(float x1, float y1, float z1, float x2, float y2, float z2, int n)
{
    float Vx = x2 - x1;
    float Vy = y2 - y1;
    float Vz = z2 - z1;
    float norme_V = sqrtf(Vx*Vx + Vy*Vy + Vz*Vz);
    float angle = asinf((z2 - z1) / norme_V);

    angle = angle * 180 / 3.14159;
    if (1) {
        printf("The incidence angle is:\n");
        angle < 0 ? angle *= (-1) : angle;
        printf("%0.2f degrees\n", angle);
    } else
        printf("The ball won't reach the paddle.\n");
}

void pong(char **av)
{
    float x1 = atof(av[1]);
    float y1 = atof(av[2]);
    float z1 = atof(av[3]);
    float x2 = atof(av[4]);
    float y2 = atof(av[5]);
    float z2 = atof(av[6]);
    int n = atoi(av[7]);

    velocity(x1, y1, z1, x2, y2, z2);
    coordinates(x1, y1, z1, x2, y2, z2, n);
    angle_calc(x1, y1, z1, x2, y2, z2, n);
}

int main(int ac, char **av)
{
    if (av[2] == "-h") {
        printf("USAGE");
        printf("    ./101pong x0 y0 z0 x1 y1 z1 n");
        printf("");
        printf("DESCRIPTION");
        printf("    x0  ball abscissa at time t - 1");
        printf("    y0  ball ordinate at time t - 1");
        printf("    z0  ball altitude at time t - 1");
        printf("    x1  ball abscissa at time t");
        printf("    y1  ball ordinate at time t");
        printf("    z1  ball altitude at time t");
        printf("    n   time shift (greater than or equal to zero, integer)");
    } else if (ac != 8) {
        printf("USAGE\n");
        printf("    ./101pong x0 y0 z0 x1 y1 z1 n\n");
        printf("\n");
        printf("DESCRIPTION\n");
        printf("    x0  ball abscissa at time t - 1\n");
        printf("    y0  ball ordinate at time t - 1\n");
        printf("    z0  ball altitude at time t - 1\n");
        printf("    x1  ball abscissa at time t\n");
        printf("    y1  ball ordinate at time t\n");
        printf("    z1  ball altitude at time t\n");
        printf("    n   time shift (greater than or equal to zero, integer)\n");
        return (84);
    }
    else
        pong(av);
    return (0);
}
