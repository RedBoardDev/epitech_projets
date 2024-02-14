/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** MY_REVSTR
*/

char    *my_revstr(char *str)
{
    int iLen;
    int i;

    char *strReverse[my_strlen(str)];
    i = 0;
    iLen = my_strlen(str) - 1;
    while (i < iLen) {
        *strReverse = str[i];
        str[i] = str[iLen];
        str[iLen] = *strReverse;
        ++i;
        --iLen;
    }
    return str;
}
