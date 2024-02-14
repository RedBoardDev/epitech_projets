/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i){
        if ((int) str[i] < 48 || (int) str[i] > 57)
            return 0;
    }
    return 1;
}

