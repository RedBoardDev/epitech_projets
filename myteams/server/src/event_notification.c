/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** event_notification.c
*/

#include "../include/teams.h"
#include <stdarg.h>

void send_event_message_to_team(teams_t *teams, char *format, ...)
{
    va_list list;

    for (int i = 0; i < MAX_USERRR; ++i) {
        if (teams->clients[i].user == NULL)
            continue;
        if (check_actual_team_contain_user_uuid(
            teams, teams->clients[i].user->uuid) == false)
            continue;
        va_start(list, format);
        va_start(list, format);
        vdprintf(teams->clients[i].socket, format, list);
        va_end(list);
    }
}

void send_event_message_to_all(teams_t *teams, char *format, ...)
{
    va_list list;

    for (int i = 0; i < MAX_USERRR; ++i) {
        if (teams->clients[i].user == NULL)
            continue;
        va_start(list, format);
        vdprintf(teams->clients[i].socket, format, list);
        va_end(list);
    }
}
