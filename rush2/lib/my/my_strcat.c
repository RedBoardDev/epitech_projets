/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
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
