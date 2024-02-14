/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD05-thomas.ott
** File description:
** init.c
*/

#include "string.h"

void string_init2(string_t *this)
{
    this->assign_c = assign_c;
    this->assign_s = assign_s;
    this->string_destroy = string_destroy;
    this->append_s = append_s;
    this->append_c = append_c;
    this->at = at_feur;
    this->clear = clear;
    this->length = length;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->copy = copy;
}

void string_init(string_t *this, const char *s)
{
    string_init2(this);
    this->c_str = c_str;
    this->empty = empty;
    this->find_s = find_s;
    this->find_c = find_c;
    this->str = strdup(s);
}
