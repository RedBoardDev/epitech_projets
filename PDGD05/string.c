/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD05-thomas.ott
** File description:
** string.c
*/

#include "string.h"

void string_destroy(string_t *this)
{
    free(this->str);
    this->str = NULL;
}

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}

void clear(string_t *this)
{
    free(this->str);
    this->str = malloc(sizeof(char) *  1);
    this->str[0] = 0;
}
