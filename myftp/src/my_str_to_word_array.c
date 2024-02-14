/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

void free_str_to_word_array(char **tab)
{
    int i = 0;
    if (tab == NULL) return;
    while (tab[i] != NULL) free(tab[i++]);
    free(tab);
}

int check_is_letter(char str, char *separator)
{
    while (*separator != '\0' && *separator++ != str);
    return *--separator == str ? 0 : 1;
}

int get_size(char const *str, char *separator)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; ++size) {
        while (str[i] != '\0' && !check_is_letter(str[i++], separator));
        if (str[i] == '\0') break;
        while (str[i] != '\0' && check_is_letter(str[i++], separator));
    }
    return size;
}

char **my_str_to_word_array(char const *str, char *separator)
{
    int nb_word = get_size(str, separator);
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int k = 0;
    for (int i = 0, g = 0, s = 0; str[i] != '\0'; i++, ++k) {
        for (; str[i] != '\0' && !check_is_letter(str[i], separator); ++i);
        if (k >= nb_word) break;
        for (s = i; check_is_letter(str[s], separator); ++s);
        result[k] = malloc(sizeof(char) * (s - i)  + 1);
        for (g = 0; i < s; i++, g++) result[k][g] = str[i];
        result[k][g] = '\0';
    }
    result[k] = NULL;
    return result;
}
