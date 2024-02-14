/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday07-thomas.ott
** File description:
** my_print_params.c
*/

void my_putchar_oui(char c)
{
    write(1, &c, 1);
}


void	my_print_params(int argc, char *argv[])
{
    int i = 0;
    while (i < argc) {
        my_putchar_oui(argv[i]);
        my_putchar_oui('\n');
        i++;
    }
}
