/*
** EPITECH PROJECT, 2022
** flags
** File description:
** flags
*/

#include "../include/corewar.h"

int func(int argc, char *argv[], flags_t **flags, debug_t *debug)
{
    int result = 0;
    if (0 == my_strcmp(argv[debug->nbr_flags], "-dump")) {
        result = flag_dump(argc, argv, flags[debug->nbr_prog],
        debug->nbr_flags);
        ++debug->cur_nbr_cycle; ++debug->tot_nbr_cycle;
    }
    if ((result == 0) && (0 == my_strcmp(argv[debug->nbr_flags], "-n"))) {
        result = flag_n(argc, argv, flags[debug->nbr_prog], debug->nbr_flags);
        ++debug->cur_prog_number; ++debug->tot_prog_number;
    }
    if ((result == 0) && (0 == my_strcmp(argv[debug->nbr_flags], "-a"))) {
        result = flag_a(argc, argv, flags[debug->nbr_prog], debug->nbr_flags);
        ++debug->cur_load_address; ++debug->tot_load_address;
    }
    if (result == 0) {
        result = flag_name(argc, argv, flags[debug->nbr_prog],
        debug->nbr_flags);
        ++debug->cur_prog_name; ++debug->tot_prog_name;
    }
    return (result);
}

int find_flags(int argc, char *argv[], flags_t **flags)
{
    int result = 0;
    debug_t debug;

    init_struct(&debug);
    for (debug.nbr_flags = 1; debug.nbr_flags < argc; ++debug.nbr_flags) {
        reinit_struct(&debug);
        result = func(argc, argv, flags, &debug);
        if ((result == 84) || (84 == (check_cur_debug(&debug))))
            return 84;
        if (flags[debug.nbr_prog]->prog_name != NULL)
            ++debug.nbr_prog;
        debug.nbr_flags = debug.nbr_flags + result;
    }
    if (84 == (check_debug(&debug)))
        return 84;
    return 0;
}

int main_flags(int argc, char *argv[])
{
    int result = 0;
    if ((argc == 2) && ((argv[1][0] == '-') && (argv[1][1] == 'h')
    && (argv[1][2] == '\0'))) {
        flag_h();
        return 0;
    }
    flags_t **flags = malloc(sizeof(flags_t *) * 4);
    for (int i = 0; i < 4; ++i) {
        flags[i] = malloc(sizeof(flags_t));
        init_flags(flags, i);
    }
    if (argc > 2)
        result = find_flags(argc, argv, flags);
    else
        return 84;
    if (result == 84)
        return 84;
    main_vm(flags);
    return 0;
}

int main(int argc, char *argv[])
{
    return main_flags(argc, argv);
}
