/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** my str upcase
*/

char *my_strupcase(car *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32 ;
    }
    return str;
}
