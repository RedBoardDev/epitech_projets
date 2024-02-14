/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_print.c
*/

#include "../include/my.h"
#include "../include/bsprintf.h"
#include "../include/structur.h"

static char const flag[] = {'s', 'c', 'd', 'i', 'p', 'x', 'X', 'b', 'o',
    'S', 'u', '\0'};
    static const int (*funct[]) (va_list, int, int) = {string_flags, char_flags,
    int_flags, int_flags, pointeur_flags, hexa_lower_flags,
    hexa_upper_flags, binary_flags, octal_flags, my_show_str,
    unsigned_flags};

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

increment_t get_indicator(increment_t increment, int count, int i, char *s)
{
    int nbr = 0;
    int lb = 0;

    increment.idc = s[i] == '+' ? i++, 1 : (s[i] == '-' ? i++, 3 :
    (s[i] == '#' ? 2 : 0));
    if (increment.idc != 0 || isnum(s[i]) || s[i] == ' ') {
        increment.idc == 2 ? i++ : i;
        increment.space = s[i] == ' ' ? i++, 1 : 0;
        for (i; isnum(s[i]) || s[i] == '.'; ++i) {
            lb = s[i + 1] == '.' ? 1 : 0;
            nbr = (nbr * 10) + s[i] - 48;
        }
    }
    nbr = nbr < 0 ? 1 : nbr;
    nbr = lb == 1 ? 0 : nbr;
    increment.idclen = nbr;
    increment.i = i;
    increment.count = count;
    return (increment);
}

int flags_check(int i, char *s, va_list list, int indic, increment_t incr)
{
    int count = 0;
    int b = 0;

    count += incr.space == 1 && incr.idclen <= 0 ?  my_putchar(' ') : 0;
    for (int j = 0; flag[j] != '\0'; ++j)
        if (s[i] == flag[j]) {
            count += (*funct[j])(list, indic, incr.idc);
            b = 1;
        }
    if (b == 0) {
        count += my_putchar('%');
        count += my_putchar(s[i]);
    } else
        return (0);
    return (count);
}

i_t my_printf_2(char *s, int i, va_list lst, i_t r)
{
    int count = 0;
    increment_t increment;

    if (s[i] == '%') {
        ++i;
        if (s[i] == '%') {
            count += my_putchar('%');
            r.i = i;
            r.count = count;
            return (r);
        }
        increment = get_indicator(increment, count, i, s);
        i = increment.i;
        count = increment.count;
        if (s[i] == 'l' && s[i++] == 'x')
            count += hexa_lower_flags(lst, increment.idclen, increment.idc);
        else
            count += flags_check(i, s, lst, increment.idclen, increment);
    } else
        count += my_putchar(s[i]);
    r.i = i;
    r.count = count;
    return (r);
}

int my_printf(char *s, ...)
{
    va_list lst;
    i_t r;
    int count = 0;

    va_start(lst, s);
    for (int i = 0; s[i] != '\0'; ++i) {
        r = my_printf_2(s, i, lst, r);
        i = r.i;
        count = r.count;
    }
    va_end(lst);
    return (count);
}
