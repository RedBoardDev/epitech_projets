/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday09-martin.d-herouville
** File description:
** my.h
*/

#ifndef BSPRINTF_H_
    #define BSPRINTF_H_

    #include <stdarg.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int my_printf(char *s, ...);
int sum_numbers(int n, ...);
int sum_strings_length(int n, ...);
void disp_stdarg(char *s, ...);
int string_flags(va_list list, int idclen, int idc);
int char_flags(va_list list, int idclen, int idc);
int int_flags(va_list list, int idclen, int idc);
int binary_flags(va_list list, int idclen, int idc);
int my_show_str(va_list list, int idclen, int idc);
int octal_flags(va_list list, int idclen, int idc);
int pointeur_flags(va_list list, int idclen, int idc);
int hexa_upper_flags(va_list list, int idclen, int idc);
int hexa_lower_flags(va_list list, int idclen, int idc);
int unsigned_flags(va_list list, int idclen, int idc);

#endif /* BSPRINTF_H_ */
