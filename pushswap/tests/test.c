/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** test.c
*/

#include "../include/my.h"
#include "../include/pushswap.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(push_swap, void_list, .init = redirect_all_std)
{
    char const *test[] = {"./push_swap", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    push_swap(11, test);
    cr_assert_stdout_eq_str("\n", "");
}

Test(push_swap, simple_list, .init = redirect_all_std)
{
    char const *test[] = {"./push_swap", "5", "3", "2", "8", "9", "0", "6", "7", "4", "1"};
    push_swap(11, test);
    cr_assert_stdout_eq_str("rra rra rra rra rra pb ra ra ra pb ra ra pb rra pb rra rra pb pb rra rra pb pa pa pa pa pa pa pa\n");
}

Test(push_swap, medium_list, .init = redirect_all_std)
{
    char const *test[] = {"./push_swap", "184739", "368", "2678590", "456", "426789", "51295", "3214", "0", "828548", "12874"};
    push_swap(11, test);
    cr_assert_stdout_eq_str("rra rra rra pb ra ra ra pb ra pb ra ra pb ra pb rra rra pb rra rra rra pb rra rra pb pa pa pa pa pa pa pa pa\n");
}

Test(push_swap, complexe_list, .init = redirect_all_std)
{
    char const *test[] = {"./push_swap", "-34567", "368", "-1", "456", "-6789503", "-34567", "15", "-156785", "-4567", "12874"};
    push_swap(11, test);
    cr_assert_stdout_eq_str("rra rra rra rra rra rra pb ra ra pb ra ra pb rra rra rra rra pb ra pb rra rra rra pb rra rra rra pb rra rra pb pa pa pa pa pa pa pa pa\n");
}

Test(push_swap, long_list, .init = redirect_all_std)
{
    char const *test[] = {"./push_swap", "-34567", "368", "-1", "456", "-6789503", "-34567", "15", "-156785", "-4567", "3456", "9876", "-23456", "12874", "12874", "13985", "5620", "-12985", "375628", "345789", "-14"};
    push_swap(21, test);
    cr_assert_stdout_eq_str("ra ra ra ra pb ra ra pb rra rra pb rra rra rra rra pb rra rra rra rra rra rra rra rra rra pb ra ra ra ra pb rra rra rra rra rra rra rra pb rra rra rra rra rra pb ra pb ra pb rra rra pb pb pb rra rra rra pb rra rra rra rra pb pb pb pb rra pb pa pa pa pa pa pa pa pa pa pa pa pa pa pa pa pa pa pa pa\n");
}

Test(push_swap, error_list, .init = redirect_all_std)
{
    char const *test[] = {"./push_swap", "5", "3A", "2", "8", "9", "0", "6", "7", "4", "1"};
    cr_assert_eq(push_swap(11, test), 84);
}
