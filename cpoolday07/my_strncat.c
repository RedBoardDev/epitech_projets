/*
** EPITECH PROJECT, 2021
** MY_STRNCAT
** File description:
** MY_STRNCAT
*/

int my_strlen1(char const *str)
{
    int len;
    len = 0;
    while   (*str++) {
        ++len;
    }
    return  len;
}

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_len = my_strlen1(dest);
    int i;

    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
