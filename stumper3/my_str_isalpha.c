/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

int my_chara_is_alpha_maj(char c)
{
    if (c < 65 || c > 90)
        return 0;
    return 1;
}

int my_chara_is_alpha_min(char c)
{
    if (c < 97 || c > 122)
        return 0;
    return 1;
}

int my_c_is_alpha(char c)
{
    if (c < 65 || c > 90 && c < 97 || c > 122)
        return 0;
    return 1;
}
