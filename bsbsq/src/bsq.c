/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-bsbsq-thomas.ott
** File description:
** bsq.c
*/

#include "../include/my.h"
#include "../include/bsq.h"

int check_char(map_t *map, int i, int j, char c)
{
    return (map->data[i + (map->lenL * j ) + j] == c);
}

// int check_square(int x, int y, map_t *map) // check si le carré est good et return 1 ou 0
// {
   
// }

int check_square(map_t *map, int x, int y, int len_square)
{
    for (int j = y; j < y + len_square; ++j) {
        for (int i = x; i < x + len_square; ++i) {
            if (check_char(map, i, j, 'o')) {
                return (0);
            }
        }
    }
    return (1);
}

void find_square(int x, int y, map_t *map) // test a partir du point x envoyé le plus gros carré
{
    int len_square = 0;
    int bool = 1;

    while (bool) {
        if (x + len_square <= map->lenL && y + len_square <= map->size) {
            bool = check_square(map, x, y, len_square);
            bool == 1 ? len_square++ : 0; // ternaire si bool == 1 ?
        } else
            bool = 0;
    }
    //write(1, map->data, 110);
    //exit (0);
    if (map->coords.bigger <= len_square) { // si le carré trouvé est + grand que le dernier + grand trouvé je le stock
        map->coords.bigger = len_square;
        printf("DFGH: %d", len_square);
        map->coords.x = x;
        map->coords.y = y;
    }
}

// int check_bordure(map_t *map, int x, int y)
// {
//     map->coords
// }

int check_map(map_t *map) // parcourir la map 1 par 1 carreau
{
    printf("CON:%d | %d\n", map->size, map->lenL);
    for (int y = 0; y < map->size; ++y) {
        for (int x = 0; x < map->lenL; ++x) {
            check_char(map, x, y, '.') ? find_square(x, y, map) : 0;
            printf("x:%d y:%d\n", x, y);
        }
    }
}

int len_ligne(char *data)
{
    int i = 0;

    for (; data[i] != '\n'; ++i);
    return (i);
}

void put_x(map_t *map, int lenL, int i, int j)
{
    map->data[i + (lenL * j)] = 'x';
}

void draw_square(map_t *map)
{
    // map->coords.bigger
    // map->coords.x
    // map->coords.y
    for (int j = map->coords.y; j < map->coords.y + map->coords.bigger; ++j) {
        for (int i = map->coords.x; i < map->coords.x + map->coords.bigger; ++i) {
            put_x(map, map->lenL, i + j, j);
        }
    }
}

int main(int argc, char **argv)
{
    char buffer_1[10];
    int rd_len = 0;
    char *buffer;
    struct stat stats;
    map_t map;

    stat(argv[1], &stats);
    read(open(argv[1], O_RDONLY), &buffer_1, 10);
    rd_len = my_getnbr(buffer_1);
    stat(argv[1], &stats);
    int len_nb = intlen(rd_len, 0);
    int fd = open(argv[1], O_RDONLY);
    buffer = malloc(sizeof(char *) * stats.st_size + 1);
    int rd = read(fd, buffer, stats.st_size);
    buffer[rd] = '\0';
    map.data = buffer + (len_nb + 1);
    map.lenL = len_ligne(map.data);
    map.size = (rd - (len_nb + 1)) / map.lenL - 1;
    //write(1, map.data, stats.st_size);
    check_map(&map);
    draw_square(&map);
    printf("bigger:%d | %d %d\n", map.coords.bigger, map.coords.x, map.coords.y);
    write(1, map.data, stats.st_size);
    free(buffer);
    return (0);
}
