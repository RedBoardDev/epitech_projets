/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_list.c
*/

#include "../../include/teams.h"

team_t *create_team_node(team_t team_node)
{
    team_t *new_team = malloc(sizeof(team_t));

    new_team->uuid = strdup(team_node.uuid);
    new_team->name = strdup(team_node.name);
    new_team->description = strdup(team_node.description);
    new_team->uuid_users = NULL;
    return new_team;
}

channel_t *create_channel_node(channel_t channel_node)
{
    channel_t *new_channel = malloc(sizeof(channel_t));

    new_channel->uuid = strdup(channel_node.uuid);
    new_channel->name = strdup(channel_node.name);
    new_channel->description = strdup(channel_node.description);
    new_channel->uuid_team = strdup(channel_node.uuid_team);
    return new_channel;
}

thread_t *create_thread_node(thread_t thread_node)
{
    thread_t *new_thread = malloc(sizeof(thread_t));

    new_thread->uuid = strdup(thread_node.uuid);
    new_thread->uuid_author = strdup(thread_node.uuid_author);
    new_thread->name = strdup(thread_node.name);
    new_thread->body = strdup(thread_node.body);
    new_thread->uuid_channel = strdup(thread_node.uuid_channel);
    new_thread->timestamp = thread_node.timestamp;
    return new_thread;
}

comment_t *create_comment_node(comment_t comment)
{
    comment_t *new_comment = malloc(sizeof(comment_t));

    new_comment->uuid = strdup(comment.uuid);
    new_comment->uuid_user = strdup(comment.uuid_user);
    new_comment->uuid_thread = strdup(comment.uuid_thread);
    new_comment->message = strdup(comment.message);
    new_comment->timestamp = comment.timestamp;
    return new_comment;
}

private_message_t *create_private_message_node(private_message_t mp)
{
    private_message_t *new_mp = malloc(sizeof(private_message_t));

    new_mp->uuid = strdup(mp.uuid);
    new_mp->uuid_receiver = strdup(mp.uuid_receiver);
    new_mp->uuid_sender = strdup(mp.uuid_sender);
    new_mp->message = strdup(mp.message);
    new_mp->message_timestamp = mp.message_timestamp;
    return new_mp;
}
