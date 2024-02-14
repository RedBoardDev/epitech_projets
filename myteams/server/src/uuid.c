/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** uuid.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <uuid/uuid.h>

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(sizeof(char) * 37);

    uuid_generate(binuuid);
    uuid_unparse_lower(binuuid, uuid);
    return uuid;
}

bool compare_uuid(char *uuid_str1, char *uuid_str2)
{
    uuid_t uuid1;
    uuid_t uuid2;

    uuid_parse(uuid_str1, uuid1);
    uuid_parse(uuid_str2, uuid2);
    return (uuid_compare(uuid1, uuid2) != 0 ? true : false);
}

void destroy_uuid(char *uuid)
{
    if (uuid != NULL) free(uuid);
}
