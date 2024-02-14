/*
** EPITECH PROJECT, 2022
** find_word
** File description:
** find_word
*/

#include <stdlib.h>
#include "my.h"

void recurs_two(char *word, int *value, char *string)
{
    if (value[1] >= value[0] && string[value[1] -
value[0]] == word[0] && value[2] == 0) {
        string[value[1] - value[0]] == word[0] - 32;
        value[1] -= value[0];
        recurs_test_word(word + 1, value, string);
    }
    if (value[1] <= (value[0] * value[0] - value[0]) -
1 && string[value[1] + value[0]] == word[0] && value[2] == 0) {
        string[value[1] + 1] = word[0] - 32;
        value[1] += value[0];
        recurs_test_word(word + 1, value, string);
    }
}

int recurs_test_word(char *word, int *value, char *string)
{
    recurs_two(word, value, string);
    if (value[1] < value[0] * value[0] - 1 && (value[1] + 1) %
value[0] != 0 && string[value[1] + 1] == word[0] && value[2] == 0) {
        string[value[1] + 1] = word[0] - 32;
        value[1] += 1;
        recurs_test_word(word + 1, value, string);
    }
    if (value[1] >= 1 && value[1] % value[0] != 0 && string[value[1] -
1] == word[0] && value[2] == 0) {
        string[value[1] - 1] = word[0] - 32;
        value[1] -= 1;
        recurs_test_word(word + 1, value, string);
    }
    if (word[0] == 0)
        value[2] = 1;
    return 0;
}

void cp_string(char *out, char *in)
{
    int i = 0;
    for (i; in[i]; ++i) {
        out[i] = in[i];
    }
    out[i] = '\0';
}

int treat_string(char *string, char *origin, int out, int ind)
{
    if (out == 0) {
        cp_string(string, origin);
    }
    if (out == 1) {
        string[ind] -= 32;
        return 1;
    }
}

int find_word(char *string, int size, char *word)
{
    char *string_cp = malloc(sizeof(char) * my_strlen(string) + 1);
    int value[3] = {size, 0, 0};
    int a = 0;
    cp_string(string_cp, string);

    for (int i = 0; string[i]; ++i) {
        if (string[i] == word[0]) {
            value[1] = i;
            recurs_test_word(word + 1, value, string);
            a = treat_string(string, string_cp, value[2], i);
        }
    }
    free(string_cp);
    return a;
}
