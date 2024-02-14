/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD05-thomas.ott
** File description:
** string2.c
*/

#include "string.h"
#include <stdio.h>

char *my_strcat(char *str1, char const *str2)
{
    int str1_len = strlen(str1);
    int i = 0;
    int j = 0;
    char *feur = malloc(sizeof(char) * (str1_len + strlen(str2)) + 1);

    for (; str1[i] != '\0' ; ++i)
        feur[i] = str1[i];
    for (; str2[j] != '\0' ; ++j)
        feur[str1_len + j] = str2[j];
    feur[str1_len + j] = '\0';
    return feur;
}

void append_s(string_t *this, const string_t *ap)
{

    char *tmp = this->str;
    char *tmp2;

    tmp2 = my_strcat(tmp, ap->str);
    this->string_destroy(this);
    this->str = strdup(tmp2);
    free(tmp2);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = this->str;
    char *tmp2;

    tmp2 = my_strcat(tmp, ap);
    this->string_destroy(this);
    this->str = strdup(tmp2);
    free(tmp2);
}

char at_feur(const string_t *this, size_t pos)
{
    size_t len = strlen(this->str);

    if (pos < len)
        return (this->str[pos]);
    return (-1);
}

int length(const string_t *this)
{
    if (!this->str)
        return (-1);
    return (strlen(this->str));
}
