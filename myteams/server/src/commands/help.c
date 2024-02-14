/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** help.c
*/

#include "../../include/teams.h"

void cmd_help(teams_t *teams, char **command, int nbr_args)
{
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "100 ta cru j'allais t'aider ptdr ?");
}
