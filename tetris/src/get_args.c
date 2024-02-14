/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** get_args.c
*/

#include "../include/struct.h"
#include "../include/tetris.h"

int get_key_from_arg(int c, args_t *args)
{
    if (!optarg)
        exit(84);
    if (c == 'l')
        args->key_left = my_atoi(optarg);
    if (c == 'r')
        args->key_right = my_atoi(optarg);
    if (c == 't')
        args->key_turn = my_atoi(optarg);
    if (c == 'd')
        args->key_drop = my_atoi(optarg);
    if (c == 'q')
        args->key_quit = my_atoi(optarg);
    if (c == 'p')
        args->key_pause = my_atoi(optarg);
}

vector_t get_size_map(args_t *args)
{
    char *backup = my_strdup(optarg);
    int i = 0;

    for (; backup[i]; ++i) {
        if (backup[i] == ',') {
            backup[i] = '\0';
            break;
        }
    }
    if (i == my_strlen(optarg))
        exit(84);
    args->map_size.x = my_atoi(backup);
    args->map_size.y = my_atoi(&optarg[i + 1]);
}

void print_all_args(args_t args)
{
    printf("help = %d\n", args.help);
    printf("level = %d\n", args.level);
    printf("key_left = %d\n", args.key_left);
    printf("key_right = %d\n", args.key_right);
    printf("key_turn = %d\n", args.key_turn);
    printf("key_drop = %d\n", args.key_drop);
    printf("key_quit = %d\n", args.key_quit);
    printf("key_pause = %d\n", args.key_pause);
    printf("map_size.x = %d\n", args.map_size.x);
    printf("map_size.y = %d\n", args.map_size.y);
    printf("without_next = %d\n", args.without_next);
    printf("debug = %d\n", args.debug);
}

void loop_parse_args(int ac, char **av, args_t *args, struct option *longopts)
{
    int c = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", longopts, NULL);

    while (c != -1) {
            if (c == 'L')
            args->level = my_atoi(optarg);
        if (c == 'l' || c == 'r' || c == 't' || c == 'd' || c == 'q'
        || c == 'p')
            get_key_from_arg(c, args);
        if (c == 'm')
            get_size_map(args);
        if (c == 'w')
            args->without_next = true;
        if (c == 'D')
            args->debug = true;
        c = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", longopts, NULL);
        }
}

args_t get_args(int ac, char **av)
{
    args_t args = {.help = false, .level = 1, .key_left = KEY_LEFT,
    .key_right = KEY_RIGHT, .key_turn = KEY_UP, .key_drop = KEY_DOWN,
    .key_quit = 'q', .key_pause = ' ', .map_size = {20, 10},
    .without_next = false, .debug = false};
    struct option longopts[] = {
    {"help", no_argument, &args.help, true},
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 'm'},
    {"without-next", no_argument, &args.without_next, true},
    {"debug", no_argument, &args.debug, true}};
    loop_parse_args(ac, av, &args, longopts);
    return (args);
}
