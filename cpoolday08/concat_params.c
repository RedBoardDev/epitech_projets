/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-thomas.ott
** File description:
** concat_params.c
*/

#include <stddef.h>

char *concat_params(int argc, char **argv)
{
    int i;
    int length = argc;
    char *str;

    for (i = 0; i < argc; ++i)
        length += my_strlen(argv[i]);
    str = malloc(sizeof(char) * (length + 1));
    for (i = 0; i < argc; ++i) {
        my_strcat(str, argv[i]);
        my_strcat(str, "\n");
    }
    str[length] = '\0';
    return my_strdup(str);
}
