/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-thomas.ott
** File description:
** my_str_to_word_array.c
*/

#include <stddef.h>

int my_show_word_array(char *const *tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        my_putstr(tab[i++]);
        my_putchar('\n');
    }
    return (0);
}

int check_is_letter(char str)
{
    if ((str < 'A' || str > 'Z')
    && (str < 'a' || str > 'z')
    && (str < '0' || str > '9'))
        return 0;
    return 1;
}

int get_size(char const *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0' ;) {
        while (str[i] != '\0' && !check_is_letter(str[i])) {
        ++i;
        }
        if (str[i] == '\0')
            break;
        for (i; str[i] != '\0' && check_is_letter(str[i]); ++i);
        ++size;
    }
    return size;
}

char **my_str_to_word_array(char const *str)
{
    int nb_word = get_size(str);
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int k = 0;

    result[nb_word] = NULL;
    for (int i = 0, w = 0; str[i] != '\0'; i++) {
        for (i; str[i] != '\0' && !check_is_letter(str[i]); ++i);
        if (k >= nb_word)
            return result;
        int s = i;
        for (s; check_is_letter(str[s]); s++);
        result[k] = malloc(sizeof(char) * s + 1);
        int g = 0;
        for (s; i < s; i++, g++)
            result[k][g] = str[i];
        result[k][g] = '\0';
        k++;
    }
    return result;
}

int main(void)
{
    char **str = "Marting, Josue et Thomas like Bitcoin";
    my_show_word_array(my_str_to_word_array(str));
    return (0);
}