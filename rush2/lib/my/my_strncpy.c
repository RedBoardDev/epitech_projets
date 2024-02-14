/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copies string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (i <  n && src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    if (n > i) {
        dest[i] = '\0';
    }
    return (dest);
}
