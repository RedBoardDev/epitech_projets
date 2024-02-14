/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <stdio.h>
#include "includes/my.h"
#include <unistd.h>
#include <stdlib.h>

int line_len(char *patern)
{
    for (int i = 0; patern[i]; ++i) {
        if (patern[i] == '@')
            return i;
    }
    return my_strlen(patern);
}

char *get_n_line(int line, char *patern)
{
    int a = 0;
    int temp = 0;

    for (int i = 0; a < line; ++i) {
        if (patern[i] == '@') {
            ++a;
            temp = i + 1;
        }
    }
    return patern + temp;
}

void str_n_add(char *out, char *in, int n)
{
    for (int i = 0; i < n; ++i) {
        out[i] = in[i];
    }
}

void create_patern(int size, char *last_chain, char *last_p_chain, char *o_chain, int current, int lpos)
{
    char *new_p = malloc(sizeof(char) * (line_len(last_chain) * line_len(last_chain) + 1) * (patern_lines_number(last_chain) * patern_lines_number(last_chain)));

    char *line_to_add;
    char *p_line_to_add;
    int cur_line = 0;
    int pos = 0;
    char *o_chain_cp = o_chain;
    
    if (current <= size) {
        for (int a = 0; a < line_len(last_chain); ++a) {
            for (int i = 0; i < patern_lines_number(last_chain); ++i) {
                line_to_add = get_n_line(i, last_chain);
                p_line_to_add = get_n_line(i, last_p_chain);
                for (int j = 0; o_chain_cp[j] != '@' && o_chain_cp[j]; ++j) {
                    if (o_chain_cp[j] == '#') {
                        str_n_add(new_p + pos, line_to_add, line_len(line_to_add));
                        pos += line_len(line_to_add);
                    }
                    if (o_chain_cp[j] == '.') {
                        str_n_add(new_p + pos, p_line_to_add, line_len(p_line_to_add));
                        pos += line_len(p_line_to_add);
                    }
                }
                str_n_add(new_p + pos, "@", 1);
                ++pos;
            }
            o_chain_cp += line_len(last_chain) + 1;
        }
        create_patern(size, new_p, new_p, o_chain, current + 1, pos);
    }
    if (current == size) {
        for (int i = 0; i < lpos; ++i) {
            if (last_chain[i] == '@')
                write(1, "\n", 1);
            else
                write(1, last_chain + i, 1);
        }
    } 
    free(new_p);
}
