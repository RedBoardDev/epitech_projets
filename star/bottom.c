/*
** EPITECH PROJECT, 2021
** Star project
** File description:
** Bottom star display
*/

void funct_print_bottom(int nb, char c, int espace, int save)
{
    for (nb; 0 < nb; --nb) {
        my_putchar(c);
    }
    print_etoile_espace_bottom(espace, save);
    my_putchar('\n');
}

void print_etoile_espace_bottom(int espace, int save)
{
    my_putchar('*');
    for (espace; espace > 0; --espace) {
        my_putchar(' ');
    }
    if (save != 1) {
        my_putchar('*');
    }
}

void calcul_bottom(int save, int cursor, int espace)
{
    while (save > 0) {
        funct_print_bottom(cursor, ' ', espace, save);
        ++cursor;
        --save;
        espace -= 2;
    }
}
