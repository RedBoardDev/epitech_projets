/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** getnbr.c
*/

int get_nbr_without_character(const char * str)
{
    int i = 0;
    int x = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            x *= 10;
            x += str[i] - '0';
        }
        ++i;
    }
    return (x);
}
