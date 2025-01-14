/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** my_strncat.c
*/

char *strncat(char *dest, const char *src, int n)
{
    int dest_len = strlen(dest);
    int i;

    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

