/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/


int patern_lines_number(char *patern)
{
    int a = 0;

    for (int i = 0; patern[i]; ++i) {
        if (patern[i] == '@')
            ++a;
    }
    return a + 1;
}
