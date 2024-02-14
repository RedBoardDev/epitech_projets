/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** init_server.c
*/

#include "../include/ftp.h"

void init_server_socket(t_ftp *ftp)
{
    int opt = true;

    ftp->server.socket = socket(AF_INET , SOCK_STREAM , 0);
    setsockopt(ftp->server.socket, SOL_SOCKET, SO_REUSEADDR,
    (char *)&opt, sizeof(opt));
    ftp->server.address.sin_family = AF_INET;
    ftp->server.address.sin_addr.s_addr = INADDR_ANY;
    ftp->server.address.sin_port = htons(ftp->server.port);
    bind(ftp->server.socket, (struct sockaddr *)&ftp->server.address,
    sizeof(ftp->server.address));
}

void init_clients(t_ftp *ftp)
{
    ftp->max_clients = 1024;
    for (size_t i = 0; i < ftp->max_clients; ++i) {
        ftp->clients[i].logged = false;
        ftp->clients[i].cmd_socket = 0;
        ftp->clients[i].data_socket = 0;
        ftp->clients[i].data_mode = mode_disable;
        ftp->clients[i].username = NULL;
    }
}

t_command *init_cmd_struct(void)
{
    int i = NBR_CMD;t_command *command = malloc(sizeof(t_command) * i);
    command[--i] = (t_command){"USER", false, &cmd_user};
    command[--i] = (t_command){"PWD", true, &cmd_pwd};
    command[--i] = (t_command){"TYPE", true, &cmd_type};
    command[--i] = (t_command){"PASV", true, &cmd_pasv};
    command[--i] = (t_command){"LIST", true, &cmd_list};
    command[--i] = (t_command){"SYST", true, &cmd_syst};
    command[--i] = (t_command){"QUIT", true, &cmd_quit};
    command[--i] = (t_command){"PASS", false, &cmd_pass};
    command[--i] = (t_command){"FEAT", true, &cmd_feat};
    command[--i] = (t_command){"CDUP", true, &cmd_cdup};
    command[--i] = (t_command){"CWD", true, &cmd_cwd};
    command[--i] = (t_command){"NOOP", true, &cmd_noop};
    command[--i] = (t_command){"DELE", true, &cmd_dele};
    command[--i] = (t_command){"HELP", true, &cmd_help};
    command[--i] = (t_command){"RETR", true, &cmd_retr};
    command[--i] = (t_command){"STOR", true, &cmd_stor};
    command[--i] = (t_command){"STOP", false, &cmd_stop};
    command[--i] = (t_command){"PORT", true, &cmd_port};
    return command;
}
