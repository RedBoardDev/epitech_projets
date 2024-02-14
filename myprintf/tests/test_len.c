/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myprintf-thomas.ott
** File description:
** test_len.c
*/

#include "../include/my.h"
#include "../include/bsprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_len_printf_1, .init = redirect_all_std)
{
    int r_value = 0;

    r_value = my_printf("btc:%c %s %d %i %p %x %X %u\n", '|', "bullrun",
    -68740, 456, 456781, 42, 42, -34567);
    cr_assert_eq(r_value, 50);
}

Test(my_printf, test_len_int_2, .init = redirect_all_std)
{
    int r_value = 0;

    r_value = my_printf("%+5d\n", 10);
    cr_assert_eq(r_value, 6);
}

Test(my_printf, test_len_int_3, .init = redirect_all_std)
{
    int r_value = 0;

    r_value = my_printf("%+5d", -10);
    cr_assert_eq(r_value, 5);
}
