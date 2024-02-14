/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** test.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(navy, file_not_existing, .init = redirect_all_std)
{
    char *test[] = {"./navy", "plane"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, error_get_maps, .init = redirect_all_std)
{
    players_t my_map;
    players_t enemy_map;
    game_t infos;
    char *navy_pos[] = {
        "2:C1:C2",
        "3:D4:F4",
        "4:B5:B8",
        "5:D7:H7",
        NULL
    };
    cr_assert_eq(get_map(navy_pos, &my_map, &enemy_map, &infos), 84);
}

Test(navy, error_check_if_nbr, .init = redirect_all_std)
{
    cr_assert_eq(check_if_nbr("056t"), 0);
}

Test(navy, good_check_if_nbr, .init = redirect_all_std)
{
    cr_assert_eq(check_if_nbr("056"), 1);
}
