/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** tests for bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/bsq.h"

Test(bsq, intermediate_map_34_137_with_obstacles_50pc, .init=cr_redirect_stdout)
{
    int file = open("tests/mouli_maps_solved/intermediate_map_34_137_with_obstacles_50pc", O_RDONLY);
    struct stat size;
    stat("tests/mouli_maps_solved/intermediate_map_34_137_with_obstacles_50pc", &size);
    char *buf = malloc(sizeof(char) * size.st_size + 1);
    int max = read(file, buf, size.st_size + 1);
    buf[max] = '\0';
    bsq("tests/mouli_maps/intermediate_map_34_137_with_obstacles_50pc");
    cr_assert_stdout_eq_str(buf, "");
    free(buf);
}

Test(bsq, intermediate_map_one_filled_column, .init=cr_redirect_stdout)
{
    int file = open("tests/mouli_maps_solved/intermediate_map_one_filled_column", O_RDONLY);
    struct stat size;
    stat("tests/mouli_maps_solved/intermediate_map_one_filled_column", &size);
    char *buf = malloc(sizeof(char) * size.st_size + 1);
    int max = read(file, buf, size.st_size + 1);
    buf[max] = '\0';
    bsq("tests/mouli_maps/intermediate_map_one_filled_column");
    cr_assert_stdout_eq_str(buf, "");
    free(buf);
}
