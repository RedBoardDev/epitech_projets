/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** main.c
*/

#include "../include/ftp.h"

int print_help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("       port is the port number on ");
    printf("which the server socket listens\n");
    printf("       path is the path to the home directory for the ");
    printf("Anonymous user\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        return (argc > 1 && (strcmp(argv[1], "-help") == 0
        || strcmp(argv[1], "-h") == 0) ? print_help() : 84);
    }
    return server(argc, argv, false);
}
