/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copies string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}