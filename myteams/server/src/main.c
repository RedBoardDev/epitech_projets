/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** main.c
*/

#include "../include/teams.h"

static int print_help(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf(
        "       port is the port number on which the server socket listens.");
    return 0;
}

int main(int argc, char **argv)
{
    int port = 0;

    if (argc != 2 || !isnumeric(argv[1])) return 84;
    port = atoi(argv[1]);
    if (!(port > 0 && port < 66000)) return 84;
    if (strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0)
        return print_help();
    return server(port);
}
