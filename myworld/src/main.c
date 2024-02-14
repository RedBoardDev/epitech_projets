/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

bool str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isnum(str[i]))
            return (false);
    }
    return (true);
}

void help(void)
{
    char *filepath = "assets/help.txt";
    char *buff = malloc(sizeof(char) * 992);
    int fd = open(filepath, O_RDONLY);
    int r = read(fd, buff, 992);

    buff[991] = '\0';
    my_putstr(buff);
    my_putchar('\n');
    close(fd);
}

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp("-h", av[1])) {
        help();
        return (0);
    } else if (ac != 1)
        return (84);
    my_world(false, (sfVector2i){-1, -1}, "");
    return (0);
}
