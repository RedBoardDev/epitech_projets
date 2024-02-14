/*
** EPITECH PROJECT, 2021
** FInalStumper
** File description:
** Main
*/

#include <unistd.h>
#include "include/my.h"

int rush_A(char buff[], int len, int len_max)
{
    if (buff[len] == 'A')
        return 4;
    else if (buff[len_max - 1] == 'C') {
        return 3;
    } else
        return 5;
}

int check_rush(char buff[], int len, int len_max)
{
    switch (buff[0]) {
    case 'o':
        return (1);
        break;
    case '/':
        return (2);
        break;
    case '*':
        return (2);
        break;
    case 'A':
        return (rush_A(buff, len, len_max));
        break;
    default:
        my_putstr("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1");
    }
}

int *check_size(char buff[], int len)
{
    int *operands = malloc(sizeof(int) * 2);
    int a = 0;
    int b = 0;

    for (; buff[a] != '\n'; ++a);
    for (int i = 0; len > i; ++i) {
        if (buff[i] == '\n')
            ++b;
    }
    operands[0] = a;
    operands[1] = b;
    return operands;
}

void print_final(int *operands, int rush_x)
{
    my_putstr("[rush1-");
    my_put_nbr(rush_x);
    my_putstr("] ");
    my_put_nbr(operands[0]);
    my_putchar(' ');
    my_put_nbr(operands[1]);
    my_putchar('\n');
}

int main(void)
{
    char buff[4096];
    int offset = 0;
    int len = 0;
    int *operands;
    int rush_x = 0;

    while ((len = read(0, buff + offset, 4096 - offset)) > 0) {
        offset = offset + len;
    }
    if (len < 0)
        return (84);
    buff[offset] = '\0';
    operands = check_size(buff, offset);
    if (operands[0] == 0 || operands[1] == 0) {
        my_putstr("none");
        return (0);
    }
    rush_x = check_rush(buff, (offset - 1) - operands[0], offset - 1);
    print_final(operands, rush_x);
    free(operands);
    return (0);
}
