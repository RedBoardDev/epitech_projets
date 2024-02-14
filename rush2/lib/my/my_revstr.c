/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Reverse a string
*/

char *my_revstr(char *str)
{
    int i;
    int n;
    char p;
    char o;

    n = 0;
    i = 0;
    while (str[i + 1] != '\0') {
        i += 1;
    }
    for (o = (i + 1) / 2; o > 0; --o) {
        p = str[i];
        str[i] = str[n];
        str[n] = p;
        n += 1;
        i -= 1;
        }
    return (str);
}
