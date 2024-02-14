/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD05-thomas.ott
** File description:
** string3.c
*/

#include "string.h"
#include <stdio.h>

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = pos;
    size_t r = 0;
    size_t str_len = strlen(this->str);

    for (; i <= str_len && r < n; ++i, ++r) {
        s[r] = this->str[i];
    }
    return (r);
}

const char *c_str(const string_t *this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    return (!this->str || this->str[0] == '\0' ? 1 : 0);
}
