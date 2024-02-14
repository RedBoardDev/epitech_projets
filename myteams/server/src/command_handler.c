/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** command_handler.c
*/

#include "../include/teams.h"

static int get_array_size(char **array)
{
    int size = 0;

    while (array[size++]);
    return size - 1;
}

static int check_command(teams_t *teams, char **command_array,
command_t *command_struct, int r)
{
    int nbr_args = 0;

    if (command_array == NULL || command_array[0] == NULL) return 0;
    nbr_args = get_array_size(command_array) - 1;
    if (nbr_args != command_struct[r].nbr_args)return 0;
    if (command_struct[r].need_login)
        if (teams->clients[teams->iterator].user == NULL)
            return 1;
    (*command_struct[r].function)(teams, command_array, nbr_args);
    write_on_file(teams);
    free_str_to_word_array(command_array);
    return 1;
}

void handler_command(teams_t *teams, char *command, command_t *command_struct)
{
    char **cmd_array = my_str_to_word_array(command, "\t\n\r\"");

    if (!cmd_array || cmd_array[0] == NULL || cmd_array[0][0] == '\0') {
        send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "500 Wrong command");
        free_str_to_word_array(cmd_array);
        return;
    }
    for (int r = 0; r < NBR_CMD; r++) {
        if (strcmp(command_struct[r].name, cmd_array[0]) == 0
        && check_command(teams, cmd_array, command_struct, r) == 1)
            return;
    }
    send_response(teams->clients[teams->iterator].socket,
    "%s\r\n", "500 Wrong command");
    free_str_to_word_array(cmd_array);
}

command_t *init_cmd_struct(void)
{
    int i = NBR_CMD;command_t *command = malloc(sizeof(command_t) * i);
    command[--i] = (command_t){"/help", true, 0, &cmd_help};
    command[--i] = (command_t){"/login", false, 1, &cmd_login};
    command[--i] = (command_t){"/logout", true, 0, &cmd_logout};
    command[--i] = (command_t){"/users", true, 0, &cmd_users};
    command[--i] = (command_t){"/user", true, 1, &cmd_user};
    command[--i] = (command_t){"/send", true, 2, &cmd_send};
    command[--i] = (command_t){"/messages", true, 1, &cmd_messages};
    command[--i] = (command_t){"/subscribe", true, 1, &cmd_subscribe};
    command[--i] = (command_t){"/subscribed", true, 0, &cmd_subscribed_0};
    command[--i] = (command_t){"/subscribed", true, 1, &cmd_subscribed_1};
    command[--i] = (command_t){"/unsubscribe", true, 1, &cmd_unsubscribe};
    command[--i] = (command_t){"/use", true, 0, &cmd_use_0};
    command[--i] = (command_t){"/use", true, 1, &cmd_use_1};
    command[--i] = (command_t){"/use", true, 2, &cmd_use_2};
    command[--i] = (command_t){"/use", true, 3, &cmd_use_3};
    command[--i] = (command_t){"/create", true, 1, &cmd_create_hub};
    command[--i] = (command_t){"/create", true, 2, &cmd_create_hub};
    command[--i] = (command_t){"/list", true, 0, &cmd_list};
    command[--i] = (command_t){"/info", true, 0, &cmd_info};return command;
}
