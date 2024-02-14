/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-mysokoban-thomas.ott
** File description:
** test.c
*/

#include "../include/my.h"
#include "../include/structure.h"
#include "../include/sokoban.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

char **set_map_test(void)
{
    char ** maps = my_str_to_word_array("##########\n"\
                                        "#        #\n"\
                                        "#        #\n"\
                                        "# PXO  ###\n"\
                                        "#        #\n"\
                                        "# OX     #\n"\
                                        "##########\n");
    return(maps);
}

Test(sokoban, check_player_position, .init = redirect_all_std)
{
    maps_t info_maps;
    char **map = set_map_test();

    find_elements(map, &info_maps);
    cr_assert_eq(info_maps.pos.x, 2);
    cr_assert_eq(info_maps.pos.y, 3);
    my_freearray(map);
}

Test(sokoban, check_size_maps, .init = redirect_all_std)
{
    struct stat stats;

    stat("tests/maps/test_size", &stats);
    int t = stats.st_size;
    cr_assert_eq(t,98);
}

Test(sokoban, check_win, .init = redirect_all_std)
{
    struct stat stats;
    char **save_map = set_map_test();
    char **map = my_str_to_word_array("##########\n"\
                                    "#        #\n"\
                                    "#        #\n"\
                                    "# P X  ###\n"\
                                    "#        #\n"\
                                    "# X      #\n"\
                                    "##########\n");

    stat("tests/maps/test_size", &stats);
    check_storage(map, save_map, 2);
    cr_assert_eq(stats.st_size, 98);
    free(save_map);
    free(map);
}

Test(sokoban, reset_maps, .init = redirect_all_std)
{
    maps_t info_maps;
    info_maps.save_map = set_map_test();
    info_maps.map = my_str_to_word_array("##########\n"\
                                        "#        #\n"\
                                        "#        #\n"\
                                        "# P X  ###\n"\
                                        "#        #\n"\
                                        "# X      #\n"\
                                        "##########\n");

    info_maps.player_start.y = 2;
    info_maps.player_start.x = 3;
    check_reset(32, &info_maps);
    cr_assert_eq(info_maps.pos.y, 2);
    cr_assert_eq(info_maps.pos.x, 3);
    free(info_maps.save_map);
    free(info_maps.map);
}

Test(sokoban, check_storage_counts, .init = redirect_all_std)
{
    maps_t info_maps;
    char **map = set_map_test();

    find_elements(map, &info_maps);
    cr_assert_eq(info_maps.count_storage, 2);
    my_freearray(map);
}

Test(sokoban, check_collisions_wall, .init = redirect_all_std)
{
    int ret;
    maps_t info_maps;
    info_maps.map = set_map_test();
    
    ret = check_collisions(0, 5, 1, &info_maps);
    cr_assert_eq(ret, 0);
    ret = check_collisions(3, 4, 1, &info_maps);
    cr_assert_eq(ret, 1);
    my_freearray(info_maps.map);
}

Test(sokoban, check_replace_storage, .init = redirect_all_std)
{
    maps_t info_maps;
    info_maps.save_map = set_map_test();
    info_maps.map = my_str_to_word_array("##########\n"\
                                        "#        #\n"\
                                        "#        #\n"\
                                        "# P X  ###\n"\
                                        "#        #\n"\
                                        "# X      #\n"\
                                        "##########\n");
    
    send_storage(&info_maps, 3, 4);
    cr_assert_eq(info_maps.map[1][1], 32);
    send_storage(&info_maps, 4, 4);
    cr_assert_eq(info_maps.map[3][4], 79);
    my_freearray(info_maps.map);
}

Test(sokoban, check_replace_boxes, .init = redirect_all_std)
{
    maps_t info_maps;
    info_maps.map = set_map_test();

    send_boxes(&info_maps, 5, 5);
    cr_assert_eq(info_maps.map[5][5], 'X');
    my_freearray(info_maps.map);
}

Test(sokoban, check_help, .init = cr_redirect_stdout)
{
    help_message();
    cr_assert_stdout_neq_str("OUI");
}

Test(sokoban, check_print_map, .init = cr_redirect_stdout)
{
    char **map = set_map_test();

    print_map(map);
    free(map);
}

Test(sokoban, check_key_pressed, .init = redirect_all_std)
{
    maps_t info_maps;
    info_maps.map = set_map_test();

    move_item(32, &info_maps);
    push_boxing(0, 0, 1, &info_maps);
    check_elements('R', &info_maps, 5, 5);
}

Test(sokoban, check_set_map, .init = redirect_all_std)
{
    maps_t info_maps;

    set_map("tests/maps/test_size", &info_maps);
    cr_assert_eq(set_map("tests/maps/test_siz", &info_maps), 84);
    free(info_maps.map);
    free(info_maps.save_map);
}
