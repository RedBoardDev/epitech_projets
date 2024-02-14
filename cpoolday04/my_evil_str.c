/*
** EPITECH PROJECT, 2021
** MY_EVIL_STR
** File description:
** Swap string's characters
*/

int strlen(char const *str)
{
    int len;
    len = 0;
    while   (*str++) {
        ++len;
    }
    return  len;
}

char *my_evil_str(char *str)
{
    int iLen;
    int i;
    char strReverse;

    i = 0;
    iLen = strlen(str) -1;
    while   (i < iLen) {
        strReverse = str[i];
        str[i] = str[iLen];
        str[iLen] = strReverse;
        ++i;
        --iLen;
    }
    return  str;
}
