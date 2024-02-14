/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** returns the number of characters found
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (*str++) {
        ++len;
    }
    return len;
}

void put_end(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\n') {
            str[i] == 0;
            break;
        }
    }
}
