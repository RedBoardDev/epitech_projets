/*
** EPITECH PROJECT, 2021
** Count Island
** File description:
** Main
*/

#include <unistd.h>

int check_if(int r, int c, char **world) {
	if (r >= 0 && c >= 0 &&
    r < my_strlen(world) &&
    c < my_strlen(world[r]) &&
    world[r][c] == 1)
        return 1;
    else
        return 0;
}

void recursive(int i, int j, int count, char **world)
{
    world[i][j] = '1';

    if (check_if(i- 1, j, world)) {
		recursive(i - 1, j, count, world);
	}
	if (check_if(i + 1, j, world)) {
		recursive(i + 1, i, count, world);
	}
	if (check_if(i, j - 1, world)) {
		recursive(i, j - 1, count, world);
	}
	if (check_if(i, j + 1, world)) {
		recursive(i, j + 1, count, world);
	}
}

int count_island(char **world)
{
    int count = 0;
    int test = 0;

    if (world == NULL || my_strlen(world) == 0)
        return 0;
    for (int i = 0; world[i] != NULL; i += 1) {
        for (int j = 0; world[i][j] != '\0'; j += 1) {
            if (world[i][j] == 'X') {
                recursive(i, j, count, world);
                ++count;
                test++;
            }
        }
    }
}
