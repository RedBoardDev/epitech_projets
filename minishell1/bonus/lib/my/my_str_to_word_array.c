/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-thomas.ott
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

int check_is_letter(char str)
{
    if ((str < 'A' || str > 'Z')
    && (str < 'a' || str > 'z')
    && (str < '0' || str > '9'))
        return 0;
    return 1;
}

int check_is_space(char str)
{
    if (str == '\0' || str == ' ' || str == '\n' || str == '\t')
        return 0;
    return 1;
}

int get_size(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0' ; ++size) {
        while (str[i] != '\0' && !check_is_space(str[++i]));
        if (str[i] == '\0')
            break;
        for (i; str[i] != '\0' && check_is_space(str[i]); ++i);
    }
    return (size);
}

char **my_str_to_word_array(char const *str)
{
    int k = 0;
    int s = 0;
    int g = 0;
    int nb_word = get_size(str);
    char **result = malloc(sizeof(char *) * (nb_word + 1));

    for (int i = 0; str[i] != '\0'; i++, ++k) {
        for (i; str[i] != '\0' && !check_is_space(str[i]); ++i);
        if (k >= nb_word) {
            result[nb_word] = NULL;
            return (result);
        }
        for (s = i; check_is_space(str[s]); ++s);
        result[k] = malloc(sizeof(char) * (s - i) + 1);
        for (g = 0; i < s; i++, g++)
            result[k][g] = str[i];
        result[k][g] = '\0';
    }
    result[nb_word] = NULL;
    return (result);
}
