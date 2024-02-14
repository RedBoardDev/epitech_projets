/*
** EPITECH PROJECT, 2021
** bscorewar
** File description:
** main.c
*/

#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int my_array_len(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; ++i)
        ++count;
    return (count + 1);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < n - 1)
        ++i;
    return (s1[i] - s2[i]);
}

int get_command(char **res)
{
    char *command = res[0];
    int len_array = my_array_len(res);

    printf("len: %d - %s, %s\n", len_array, res[0], res[1]);
    if (!my_strncmp(command, "add", 3))
        return (0);
    if (!my_strncmp(command, "sub", 3))
        return (1);
    if (!my_strncmp(command, "mul", 3))
        return (2);
    if (!my_strncmp(command, "put", 3))
        return (3);
}

int put_file(char **res, int fd)
{
    char c = 1;
    int nbr_1 = 0;
    int nbr_2 = 0;
    int ret = get_command(res);

    switch (ret) {
    case 0:
        write(fd, &c, sizeof(char));
        break;
    case 1:
        c = 2;
        write(fd, &c, sizeof(char));
        break;
    case 2:
        c = 3;
        write(fd, &c, sizeof(char));
        break;
    case 3:
        c = 4;
        write(fd, &c, sizeof(char));
        break;
    default:
        return (84);
        break;
    }
    if (ret == 3) {
        c = strlen(res[1]);
        write(fd, &c, sizeof(int));
        write(fd, res[1], strlen(res[1]));
    } else if (my_array_len(res) != 4)
        return (84);
    else {
        nbr_1 = atoi(res[1]);
        nbr_2 = atoi(res[2]);
        write(fd, &nbr_1, sizeof(int));
        write(fd, &nbr_2, sizeof(int));
    }
    return (0);
}

int main(int argc, char **argv)
{
    size_t size = 0;
    char *buf = NULL;
    char **res = NULL;
    int fd;
    // int fd = open(argv[1], O_RDONLY);

    // close(fd);
    fd = open("one-structure.yolo", O_CREAT | O_WRONLY, 0664);
    for (int i = 0; getline(&buf, &size, stdin) != -1; ++i) {
        res = my_str_to_word_array(buf, ' ');
        if (put_file(res, fd) == 84)
            return (84);
    }
    return (0);
}
