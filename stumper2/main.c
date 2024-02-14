/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/


#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "structure.h"

int w_flag(boggle_t *boggle)
{
    int a = find_word(boggle->grid, boggle->size, boggle->word);
    char g[1] = " ";
    g[0] = 34;

    write_tab(boggle->grid, boggle->size);
    if (a == 0) {
        write(2, "The word ", 9);
        write(2, g, 1);
        write(2, boggle->word, my_strlen(boggle->word));
        write(2, g, 1);
        write(2, " is not in the grid\n", 21);
        boggle->word[0] = 0;
    }
    if (a == 1)
        exit(0);

}

void put_resp(int a, char *g, char *temp, boggle_t boggle)
{
    if (a == 1) {
        write_tab(boggle.grid, boggle.size);
        free(temp);
        exit(0);
    }
    write(2, "The word ", 9);
    write(2, g, 1);
    write(2, temp, my_strlen(temp));
    write(2, g, 1);
    write(2, " is not in the grid\n", 21);
}

int main_clock(boggle_t boggle)
{
    int a = 0;
    char *temp = malloc(sizeof(char) * boggle.size * boggle.size + 1);
    char g[1] = " ";
    int b = 0;
    g[0] = 34;

    if (!boggle.word[0])
        write_tab(boggle.grid, boggle.size);

    while (1) {
        if (boggle.word[0])
            w_flag(&boggle);
        write(1, ">", 1);
        b = read(0, temp, boggle.size * boggle.size + 1);
        put_end(temp);
        a = find_word(boggle.grid, boggle.size, temp);
        put_resp(a, g, temp, boggle);
    }
}

void put_first_and_last_line (int size)
{
    for (int i = 0; i < size * 2 + 3; ++i) {
        write(1, "+", 1);
    }
    write(1, "\n", 1);
}

void write_tab(char *string, int size)
{
    int a = 0;
    put_first_and_last_line(size);
    for (int i = 0; i < size; ++i) {
        write(1 , "| ", 2);
        for (int j = 0; j < size; ++j) {
            write(1, string +  a, 1);
            ++a;
            write(1 , " ", 1);
        }
        write(1, "| \n", 3);
    }
    put_first_and_last_line(size);
}
