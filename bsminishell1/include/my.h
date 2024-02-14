/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday09-thomas.ott
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int check_prime_p(int nb);
int my_getnbr(const char *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int * array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, const char *src, int n);
int my_strncmp(char const * s1, char const * s2, int n);
char *my_strncpy(char *dest, char const *src, int  n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int my_swap(int *a, int *b);
int check_prime_p(int nb);
int my_find_prime_sup(int nb);
int intlen(int i, int count);
void convert_base(int nb, char *base);
int isnum(char c);
int my_atoi(char const *src);
char *my_strdup(char const *src);
char *my_itoa(int nb);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);

#endif
