/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** MY_STRCAT
*/

int my_strlen0(char const *str)
{
    int len;
    len = 0;
    while   (*str++) {
        ++len;
    }
    return  len;
}

char *my_strncat(char *dest, const char *src)
{
    int dest_len = my_strlen0(dest);
    int i;

    for (i = 0 ;src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
