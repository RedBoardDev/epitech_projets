/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *str, char *comp)
{
    for (int i = 0; comp[i] != '\0'; ++i) {
        if (str[i] == '\0' && comp[i] != '\0')
            return (1);
        if (comp[i] != str[i])
            return (1);
    }
    return (0);
}
