/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** Reproduce the behavior of the strstr function
*/

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int b;
    i = 0;
    b = 0;
    while (str[i] != '\0') {
        while (str[i] == to_find[b] && b < my_strlen(to_find)) {
            b += 1;
            i += 1;
        }
        if (b == my_strlen(to_find))
            return (to_find);
        i += 1;
        b = 0;
        }
    return (0);
}
