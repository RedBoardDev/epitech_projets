/*
** EPITECH PROJECT, 2022
** B-CPE-201-MLH-2-1-corewar-thomas.ott
** File description:
** flags
*/

#include "../include/corewar.h"

void flag_h(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]"\
    "[-a load_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps the"\
    "memory after the nbr_cycle execution (if the round isn't"\
    "already over) with the following format: 32 bytes/line\nin hexadecimal"\
    "(A0BCDEFE1DD3...)\n-n prog_number sets the next program's number."\
    "By default, the first free number in the parameter order\n"\
    "-a load_address sets the next program's loading address. When no "\
    "address is specified, optimize the addresses so that the processes"\
    "are as far\naway from each other as possible."\
    "The addresses are MEM_SIZE modulo.\n");
    exit(0);
}

int flag_dump(int argc, char *argv[], flags_t *flags, int nbr_flags)
{
    int result = 0;

    if ((nbr_flags + 1) < argc) {
        result = my_str_is_int(argv[nbr_flags + 1]);
        if (result == -1)
            return 0;
        flags->nbr_cycle = result;
        return 1;
    }
    return 0;
}

int flag_n(int argc, char *argv[], flags_t *flags, int nbr_flags)
{
    int result = 0;

    if ((nbr_flags + 1) < argc) {
        result = my_str_is_int(argv[nbr_flags + 1]);
        if (result == -1)
            return 0;
        flags->prog_number = result;
        return 1;
    }
    return 0;
}

int flag_a(int argc, char *argv[], flags_t *flags, int nbr_flags)
{
    int result = 0;

    if ((nbr_flags + 1) < argc) {
        result = my_str_is_int(argv[nbr_flags + 1]);
        if (result == -1)
            return 0;
        flags->load_address = result;
        return 1;
    }
    return 0;
}

int flag_name(int argc, char *argv[], flags_t *flags, int nbr_flags)
{
    int result = 0;
    int n = 0;

    for (; argv[nbr_flags][n] != '\0'; ++n);
    if (n <= 4)
        return 84;
    if (1 == my_strcmp(argv[nbr_flags] + (n - 4), ".cor"))
        return 84;
    flags->prog_name = argv[nbr_flags];
    return 0;
}
