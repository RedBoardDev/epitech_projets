/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** MY_STRNCPY
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_string_in_empty_array)
{
    char    dest[6] = "0";

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
