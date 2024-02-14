/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** check_arguments.c
*/

#include <sys/stat.h>
#include "../include/ftp.h"

int init_ftp_struct(int argc, char **argv, t_ftp *ftp)
{
    struct stat sb;
    if (argc != 3)
        return 84;
    if (!isnumeric(argv[1]) && atoi(argv[1]) > 0 && atoi(argv[1]) < 66000)
        return 84;
    if (stat(argv[2], &sb) != 0 && !S_ISDIR(sb.st_mode))
        return 84;
    ftp->server.port = atoi(argv[1]);
    if (chdir(argv[2]) == -1)
        return 84;
    return 0;
}
