/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-martin.d-herouville
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_is_alphanum(char const *str, int i)
{
    if (str[i] < '0' || (str[i] > '9' && str[i] < 'A') || (str[i] > 'Z' &&
    str[i] < 'a') || str[i] > 'z')
        return (0);
    else
        return (1);
}

char **strtowordarray2(char const *str, int var_word, char **new, int k)
{
    for (int all_letters = 0; str[all_letters] != '\0'; ++all_letters) {
        int size = 0;

        if (my_is_alphanum(str, all_letters) == 1) {
            for (int j = all_letters; str[j] != '\0'
            && (my_is_alphanum(str, j)); ++j) {
                ++size;
            }
            new[var_word] = malloc(sizeof(char) * (size + 1));
            for (k = 0; k < size; ++k) {
                new[var_word][k] = str[all_letters];
                ++all_letters;
            }
            new[var_word][k] = '\0';
            ++var_word;
        }
    }
    new[var_word] = NULL;
    return (new);
}

char **my_str_to_word_array(char const *str)
{
    char **new;
    int nb_words = 0;
    int lettres = 0;
    int var_word = 0;
    int k = 0;

    for (int i = 0; i < my_strlen(str); ++i) {
        int j = 0;
        if (my_is_alphanum(str, i)) {
            for (j = i; str[j] != '\0' && (my_is_alphanum(str, j)); ++j)
                ++i;
            ++nb_words;
        }
    }
    new = malloc(sizeof(char *) * (nb_words + 1));
    new = strtowordarray2(str, var_word, new, k);
    return (new);
}

/*int main(void)
{
    char *str = "qfs  4  jE su5is dqsmfljhqds slmfg feauepzfh ";

    my_show_word_array(my_str_to_word_array(str));
    return (0);
}*/
