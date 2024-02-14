/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

int my_str_isstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i){
        if ((int) str[i] < 97 || (int) str[i] > 122)
            return 0;
    }
    return 1;
}
