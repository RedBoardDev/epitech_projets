/*
** EPITECH PROJECT, 2022
** hidenp
** File description:
** stumper 02 - hidenp
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int len = 0;

    while (*str++) {
        ++len;
    }
    return (len);
}

int check_occurencie(char *needle, char *haystack)
{
    int y = my_strlen(needle);

    for (int i = 0, r = 0; haystack[i] != '\0'; ++i) {
        if (r >= y)
            return (1);
        if (haystack[i] == needle[r])
            ++r;
        if (r >= y)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int booli = 0;

    if (ac < 3) {
        write(2, "Usage: ./hidenp needle haystack\n", 32);
        return (84);
    }
    booli = check_occurencie(av[1], av[2]);
    if (booli == 1)
        write(1, "1\n", 2);
    else
        write(1, "0\n", 2);
    return (0);
}
