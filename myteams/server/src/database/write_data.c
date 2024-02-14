/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** write_data.c
*/

#include "../../include/struct.h"
#include "../../include/teams.h"

void print_channel_into_file(node_t *channel_list, int file, char *filename)
{
    channel_t *channel;
    node_t *buff = channel_list;

    dprintf(file, "##channel\n");
    while (buff != NULL) {
        channel = buff->data;
        dprintf(file, "%s~%s~%s~%s\n", channel->name, channel->description,
        channel->uuid, channel->uuid_team);
        buff = buff->next;
    }
}

void print_thread_into_file(node_t *thread_list, int file, char *filename)
{
    thread_t *thread;
    node_t *buff = thread_list;

    dprintf(file, "##thread\n");
    while (buff != NULL) {
        thread = buff->data;
        dprintf(file, "%s~%s~%s~%s~%s~%ld\n", thread->name, thread->body,
        thread->uuid, thread->uuid_author,
        thread->uuid_channel, thread->timestamp);
        buff = buff->next;
    }
}

void print_comment_into_file(node_t *comment_list, int file, char *filename)
{
    comment_t *comment;
    node_t *buff = comment_list;

    dprintf(file, "##comment\n");
    while (buff != NULL) {
        comment = buff->data;
        dprintf(file, "%s~%s~%s~%s~%ld\n", comment->uuid, comment->uuid_user,
        comment->uuid_thread, comment->message, comment->timestamp);
        buff = buff->next;
    }
}

void write_on_file(teams_t *teams)
{
    int file = 0;
    char *filename = "datafile.txt";

    file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (file == -1) return;
    print_user_into_file(teams->user, file, filename);
    print_team_into_file(teams->team, file, filename);
    print_channel_into_file(teams->channel, file, filename);
    print_thread_into_file(teams->thread, file, filename);
    print_comment_into_file(teams->comment, file, filename);
    print_private_message_into_file(teams->private_message, file, filename);
}
