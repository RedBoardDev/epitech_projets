/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myprintf-thomas.ott
** File description:
** function_flags.c
*/

#include "../include/my.h"
#include "../include/bsprintf.h"
#include "../include/structur.h"
#include <stdlib.h>

int string_flags(va_list list, int idclen, int idc)
{
    char *str = va_arg(list, char *);
    int count = 0;

    idclen = idclen > my_strlen(str) ? idclen - my_strlen(str) + 1 : idclen;
    if (idclen > 1 && idc == 1) {
        for (int i = idclen - 1;  i > 0; --i)
            count += my_putchar(' ');
    }
    count += my_putstr(str);
    if (idclen > 1 && idc == 3) {
        for (int i = idclen - 1;  i > 0; --i)
            count += my_putchar(' ');
    }
    return (count);
}

int char_flags(va_list list, int idclen, int idc)
{
    char c = va_arg(list, int);
    int count = 0;

    if (idclen > 1 && idc == 1) {
        for (int i = idclen - 1;  i > 0; --i)
            count += my_putchar(' ');
    }
    count += my_putchar(c);
    if (idclen > 1 && idc == 3) {
        for (int i = idclen - 1;  i > 0; --i)
            count += my_putchar(' ');
    }
    return (count);
}

int int_flags(va_list list, int idclen, int idc)
{
    long nbr = va_arg(list, int);
    int nb_len = 0;
    int sub = 0;

    if (nbr < 0) {
        nbr = nbr * (-1);
        sub = 1;
        nb_len++;
    }
    nb_len = sub = 1 && idclen == 1 ? nb_len - 1 : nb_len;
    for (int nb_buff = nbr; nb_buff > 0 && idclen > 0; nb_len++)
        nb_buff /= 10;
    nb_len = idclen > nb_len ? idclen - nb_len : nb_len;
    for (int len_buff = nb_len; len_buff > 0 && idclen != 0; --len_buff)
        nb_len += my_putchar(' ');
    sub == 1 ? my_putchar('-') : (idc == 1 ? my_putchar('+') : sub);
    my_put_nbr_2(nbr, nb_len);
    return (nb_len);
}

int pointeur_flags(va_list list, int indicator, int idc)
{
    unsigned int i = va_arg(list, int);

    my_putstr("0x");
    return (convert_base(i, "0123456789abcdef") + 2);
}

int my_show_str(va_list list, int idclen, int idc)
{
    char *str = va_arg(list, char *);
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 0 && str[i] <= 31){
            my_putchar('\\');
            count +=  1;
            count += (str[i] <= 7) ? my_putstr("00") : my_putchar('0');
            count += convert_base(str[i], "01234567");
        } else
            count += my_putchar(str[i]);
    }
    return (count);
}
