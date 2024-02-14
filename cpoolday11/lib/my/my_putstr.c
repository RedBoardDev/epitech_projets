/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** displays one-by-one the caracters of a string
*/

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}
