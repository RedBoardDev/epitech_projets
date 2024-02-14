/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** read_file.c
*/

#include "../include/struct.h"
#include "../include/tetris.h"
#include <sys/types.h>
#include <dirent.h>

bool error_handling_file(char *buff)
{
    int i = 0;
    if (!isnum(buff[0]))
        return (false);
    for (; buff[i] != ' '; ++i)
        if (!isnum(buff[i]))
            return (false);
    for (++i; buff[i] != ' '; ++i)
        if (!isnum(buff[i]))
            return (false);
    for (++i; buff[i] != ' ' && buff[i] != '\n'; ++i)
        if (!isnum(buff[i]))
            return (false);
    if (buff[i] != '\n')
        return (false);
    for (i = 0; buff[i] != '\n'; ++i);
    for (int j = i + 1; buff[j] != '\0'; ++j)
        if (buff[j] != ' ' && buff[j] != '*' && buff[j] != '\n')
            return (false);
    return (true);
}

int custom_strlen(char const *str)
{
    int count = my_strlen(str);

    for (int i = count - 1; str[i] == ' '; --i)
        --count;
    return (count);
}

bool error_handling_size_piece(tetrimino_t tet)
{
    int size_max_str = 0;
    int count = 0;

    if (tet.color > 99)
        return (false);
    for (int i = 0; tet.piece[i]; ++i) {
        if (my_strlen(tet.piece[i]) > size_max_str)
            size_max_str = custom_strlen(tet.piece[i]);
        ++count;
    }
    if (size_max_str != tet.size.x)
        return (false);
    if (count != tet.size.y)
        return (false);
    return (true);
}

tetrimino_t set_one_struct(char *buff)
{
    tetrimino_t tetrimino = {true};
    int i = 0;

    tetrimino.size.x = my_getnbr(buff);
    for (; buff[i] != ' '; ++i);
    tetrimino.size.y = my_getnbr(&buff[i + 1]);
    ++i;
    for (; buff[i] != ' '; ++i);
    tetrimino.color = my_getnbr(&buff[i + 1]);
    ++i;
    for (; buff[i] != '\n'; ++i);
    tetrimino.piece = my_str_to_word_array(&buff[i + 1]);
    return (tetrimino);
}

tetrimino_t open_file(char *file_name)
{
    struct stat stat_buff;
    char *filepath = my_strcat(my_strcat(FOLDER, "/"), file_name);
    int s = stat(filepath, &stat_buff);
    char *buff = malloc(sizeof(char) * (stat_buff.st_size + 1));
    int fd = open(filepath, O_RDONLY);
    tetrimino_t error = {.active = false, .piece = NULL, .name = NULL, .size = {-1, -1}, .color = -1};
    tetrimino_t ret;

    if (fd == -1)
        exit(0);
    if (read(fd, buff, stat_buff.st_size) == 0)
        exit(0);
    buff[stat_buff.st_size] = '\0';
    close(fd);
    if (!error_handling_file(buff))
        return (error);
    ret = set_one_struct(buff);
    if (!error_handling_size_piece(ret))
        return (error);
    return (ret);
}
