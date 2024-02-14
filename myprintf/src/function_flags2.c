/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myprintf-thomas.ott
** File description:
** function_flags2.c
*/

#include "../include/my.h"
#include "../include/bsprintf.h"

int unsigned_flags(va_list list, int idclen, int idc)
{
    unsigned int i = va_arg(list, int);

    return (convert_base(i, "0123456789"));
}

int binary_flags(va_list list, int idclen, int idc)
{
    int i = va_arg(list, int);

    if (i < 0) {
        i *= (-1);
    }
    return (convert_base(i, "01"));
}

int hexa_upper_flags(va_list list, int idclen, int idc)
{
    unsigned int i = va_arg(list, int);
    int count = 0;

    if (idc == 2)
            count += my_putchar('0');
    return (convert_base(i, "0123456789ABCDEF") + count);
}

int hexa_lower_flags(va_list list, int idclen, int idc)
{
    unsigned int i = va_arg(list, int);
    int count = 0;

    if (idc == 2)
        count += my_putstr("0x");
    return (convert_base(i, "0123456789abcdef") + count);
}

int octal_flags(va_list list, int idclen, int idc)
{
    int i = va_arg(list, int);
    int count = 0;
    int nb_len = 0;

    i < 0 ? i *= (-1), ++count : i;
    for (int nb_buff = i; nb_buff > 0 && idclen > 0; nb_len++)
        nb_buff /= 10;
    nb_len = idclen > nb_len ? idclen - nb_len : nb_len;
    if (idclen >= 0 && idc == 1) {
        for (nb_len; nb_len - 1 > 0 && idclen != 0; --nb_len)
            count += my_putchar(' ');
    }
    if (idc == 2)
        count += my_putchar('0');
    count += convert_base(i, "01234567");
    if (idclen >= 0 && idc == 3) {
        for (; nb_len - 1 > 0 && idclen != 0; --nb_len)
            count += my_putchar(' ');
    }
    return (count);
}
