/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** my_strcapitalize.c
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0;str[i] != '\0'; ++i) {
        if ((str[i] >= 97 && str[i] <= 122) && str[i] != '\0'
            && (str[i-1] >= 23 && str[i-1] <= 47)) {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
