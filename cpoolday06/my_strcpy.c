/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** MY_STRCPY
*/

char	*my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i++];
    }
    dest[i] = '\0';
    return (dest);
}
