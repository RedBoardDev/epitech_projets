/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-thomas.ott
** File description:
** my_str_to_word_array.c
*/

#include "../include/asm.h"

bool space(char c, char separator)
{
    return (c == separator);
}

int count_words(char const *str, char separator)
{
    int nbr_words = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (i > 0 && space(str[i], separator) &&
        !space(str[i + 1], separator))
            ++nbr_words;
    if (str[my_strlen(str) - 1] != separator)
        ++nbr_words;
    return (nbr_words);
}

int count_letters(char const *str, char separator)
{
    int i = 0;

    while (!space(str[i], separator) && str[i] != '\0')
        ++i;
    return (i);
}

char **set_arr(char **new_arr, int i_a, int j_a)
{
    new_arr[i_a][j_a] = '\0';
    new_arr[++i_a] = NULL;
    return (new_arr);
}

char **my_str_to_word_arrays(char const *str, char separator)
{
    int nbr_words = count_words(str, separator);
    int i_a = 0;
    int j_a = 0;
    int i = 0;
    char **new_arr = malloc(sizeof(char *) * (nbr_words + 1));
    for (; space(str[i], separator); ++i);
    int nbr_letters = count_letters(&str[i], separator);
    new_arr[i_a] = malloc(sizeof(char) * (nbr_letters + 1));
    for (; str[i] != '\0'; ++i) {
        if (i > 0 && space(str[i], separator) && !space(str[i - 1], separator))
            new_arr[i_a][j_a] = '\0';
        space(str[i], separator) &&
        !space(str[i + 1], separator) && str[i + 1] != '\0' ?
        j_a = 0, nbr_letters = count_letters(str + i + 1, separator),
        new_arr[++i_a] = malloc(sizeof(char) * (nbr_letters + 1)) : 0;
        !space(str[i], separator) &&
        str[i] != '\0' ? new_arr[i_a][j_a++] = str[i] : 0;
    }
    new_arr = set_arr(new_arr, i_a, j_a);
    return (new_arr);
}