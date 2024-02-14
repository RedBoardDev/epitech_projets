/*
** EPITECH PROJECT, 2022
** Short Words
** File description:
** diplays words in alphabetical order
*/

int count_word(char **av)
{
    int count = 0;

    while(av[count] != '\0') {
        ++count;
    }
    return (count);
}

int sort_words(char **av)
{
    int count_word = f_counts_words(av);

    printf("count %d\n", count_word);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (sort_words(av));
}
