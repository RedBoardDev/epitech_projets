/*
** EPITECH PROJECT, 2022
** Short Words
** File description:
** diplays words in alphabetical order
*/

#include "../include/shortwords.h"

int check_letters(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && 'Z'))
        return (1);
    return (0);
}

int f_count_words(char *av)
{
    int count = 0;

    for (int i = 0; av[i] != '\0';) {
        while (av[i] != '\0' && !check_letters(av[i])) {
            ++i;
        }
        if (av[i] == '\0')
            break;
        ++count;
        while (av[i] != '\0' && check_letters(av[i])) {
            ++i;
        }
    }
    return (count);
}

int search_ib(int *i_b, int count_word, int i)
{
    for (int y = 0; y <= count_word; ++y) {
        if (i == i_b[y])
            return (0);
    }
    return (1);
}

int sort_words(char *av)
{
    int count_word = f_count_words(av);
    char first_c;
    int i = 0;
    int i_b_index = 0;
    int *i_b = malloc(sizeof(int) * (count_word));
    char **word = my_str_to_word_array(av);
    int total = 0;
    
    first_c = word[0][0];
    while (total <= count_word) {
        for (i = 0; i < count_word - 1; ++i) {
            printf("ib:%d | %d\n", search_ib(i_b, count_word, i), i);
            if (word[i][0] <= first_c && search_ib(i_b, count_word, i)) {
                first_c = word[i][0];
                total += 1;
                i_b[i_b_index] = i;
                ++i_b_index;
            }
        }
        my_putstr(word[i]);
    }
    free(i_b);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (sort_words(av[1]));
}
