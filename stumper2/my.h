/*
** EPITECH PROJECT, 2022
** myh
** File description:
** myh
*/

#ifndef MY_H_
    #define MY_H_

#include "structure.h"

int isnum(char c);
int my_str_isnum(char const *str);
int my_str_isstr(char const *str);
int my_strcmp(char *str1, char *str2);
int my_atoi(char const *src);
int my_strlen(char const *str);
void write_tab(char *string, int size);
int main_clock(boggle_t boggle);
void put_end(char *str);
int find_word(char *string, int size, char *word);
int recurs_test_word(char *word, int *value, char *string);

#endif //MY_H_
