/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** error_handling.c
*/

#include "../include/asm.h"
#include "../include/op.h"

static int len_str(char const *str)
{
    int len = 0;
    int first_quo = 0;

    while (str[len] != '\0' && str[len] != '\n') {
        if (str[len] == '\"')
            ++first_quo;
        if (first_quo == 2)
            return (len);
        ++len;
    }
    return (len);
}

static int my_strlen_2(char const *str)
{
    int len = len_str(str);
    int complete_len = 0;

    while (str[complete_len] != '\0' && str[complete_len] != '\n')
        ++complete_len;
    --complete_len;
    if (complete_len != len || len <= 0)
        exit(84);
    return len;
}

static int check_comment_syntaxe(char *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == '\"')
            return (0);
    exit(84);
}

int error_handling_begin_name(header_t *header, char *str, int i_line)
{
    int i = 0;
    int len_name = 0;

    if (i_line != 0)
        return (0);
    check_comment_syntaxe(str);
    while (str[i] != '\"')
        ++i;
    for (int j = 0; j < i; ++j)
        ++str;
    i = 0;
    len_name = my_strlen_2(str);
    if (len_name > PROG_NAME_LENGTH)
        exit(84);
    for (int r = 0; i < len_name; ++r) {
        if (str[r] != '"')
            header->prog_name[i++] = str[r];
    }
    header->prog_name[i - 1] = '\0';
    return (1);
}

int error_handling_begin_comment(header_t *header, char *str, int i_line)
{
    int i = 0;
    int len_comment = 0;

    if (i_line != 1)
        return (0);
    check_comment_syntaxe(str);
    while (str[i] != '\"')
        ++i;
    for (int j = 0; j < i; ++j)
        ++str;
    i = 0;
    len_comment = my_strlen_2(str);
    if (len_comment > COMMENT_LENGTH)
        exit(84);
    for (int r = 0; i < len_comment; ++r) {
        if (str[r] != '\"')
            header->comment[i++] = str[r];
    }
    header->comment[i - 1] = '\0';
    return (1);
}
