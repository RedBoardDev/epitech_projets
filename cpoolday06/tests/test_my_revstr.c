/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** MY_REVSTR
*/

#include <criterion/criterion.h>

Test(my_revstr, copy_string_in_empty_array)
{
    char    str[8] = "Bitcoin";

    my_revstr(str);
    cr_assert_str_eq(str, "nioctiB");
}
