/*
** EPITECH PROJECT, 2021
** 103cipher
** File description:
** main.c
*/

#include "include/struct.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// int multiply_two_matrices(int **mat_a, int **mat_b, int n)
// {
//     int a1 = 0;
//     int a2 = 0;
//     int b1 = 0;
//     int b2 = 0;
//     int **mat_dest = malloc(sizeof(int *) * (n + 1));
//     for (int i = 0; i < n; ++i)
//         mat_dest[i] = malloc(sizeof(int) * (n + 1));
// }

int **create_matrice(char *av, int n, int size)
{
    int line = (size + n) / n;
    int **matrice = malloc(sizeof(int *) * (line + 1));

    for (int i = 0; i < line; ++i)
        matrice[i] = malloc(sizeof(int) * (n + 1));

    for (int i = 0, count = 0; count < size; ++i) {
        for (int j = 0; j < n; ++j) {
            matrice[i][j] = av[count];
            ++count;
        }
        matrice[i][n] = '\0';
    }
    matrice[line] = NULL;
    // for (int i = 0; i < line; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         printf("%d ", matrice[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    return (matrice);
}

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

void print_array(int **tab, int size, int n)
{
    int zero = 0;
    int j = 0;

    for (int r = 0; tab[r] != NULL; ++r)
        for (int f = 0; tab[r][f] != '\0'; ++f)
            ++zero;
    zero = 9 - zero;
    for (int i = 0; tab[i] != NULL; ++i) {
        for (j = 0; tab[i][j] != '\0'; ++j)
            j == 2 ? printf("%d", tab[i][j]) : printf("%-5d", tab[i][j]);
        j == 3 ? printf("\n") : 0;
    }
    for (; zero > 0; --zero)
        zero != 1 ? printf("%-5d", 0) : printf("%d", 0);
    printf("\n");
}

int main(int ac, char **av)
{
    if (ac < 4 || ac > 4)
        return (84);
    if (av[3][0] != '0' && av[3][0] != '1')
        return (84);
    if (av[3][1] != '\0')
        return (84);
    int n = 3;
    int **message = create_matrice(av[1], 3, strlen(av[1]));
    int **dest = create_matrice(av[1], 3, strlen(av[1]));
    int **key = create_matrice(av[2], 3, strlen(av[2]));

    printf("Key matrix:\n");
    print_array(key, strlen(av[2]), n);

    // for (int i = 0; message[i] != NULL; ++i) {
    //     for (int j = 0; message[i][j] != '\0'; ++j) {
    //         dest[i][j]
    //     }
    // }
}

// int main(int ac, char **av)
// {
//     int n = atoi(av[2]);
//     int size = strlen(av[1]);
//     int line = size / n;
//     int *matrice = malloc(sizeof(int) * size);

//     for (int i = 0; i < size; ++i) {
//         matrice[i] = av[1][i];

//     }
//     for (int i = 0; i < size; ++i) {
//         printf("%d ", matrice[i]);
//         if ((i + 1) % n == 0)
//             printf("\n");
//     }
// }
