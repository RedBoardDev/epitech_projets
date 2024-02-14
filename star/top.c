/*
** EPITECH PROJECT, 2021
** Star project
** File description:
** Top star display
*/

void print_etoile_espace_top(int espace)
{
    my_putchar('*');
    if (espace != -1) {
        for (espace; 0 < espace; --espace) {
            my_putchar(' ');
        }
        my_putchar('*');
    }
}

void print_funct_print_top(int nb, char c, int espace)
{
    for (nb; 0 < nb; --nb) {
        my_putchar(c);
    }
    print_etoile_espace_top(espace);
    my_putchar('\n');
}

int calcul_funct_top(int save, int cursor, int espace)
{
    while (save > 0) {
        print_funct_print_top(cursor, ' ', espace);
        --cursor;
        --save;
        espace += 2;
    }
    return espace;
}
