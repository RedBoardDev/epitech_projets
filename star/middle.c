/*
** EPITECH PROJECT, 2021
** Star project
** File description:
** Middle star display
*/

void print_flat(int size, int espace)
{
    int save;

    save = size;
    for (size; 0 < size; --size) {
        my_putchar('*');
    }
    for (espace; 0 < espace; --espace) {
            my_putchar(' ');
    }
    for (save; 0 < save; --save) {
        my_putchar('*');
    }
    my_putchar('\n');
}

int calcul_middle(int espace_flat, int espace, int size)
{
    espace_flat = espace-2;
    print_flat((size * 2) + 1, espace_flat);
    espace = (size * 3 - 1) * 2 - 3;
    re_print_middle(espace, size);

    re_print_middle_reverse(size*4-1, size-1);
    print_flat((size * 2) + 1, espace_flat);
    return espace_flat;
}

void re_print_middle_reverse(int espace, int size)
{
    int save_decale = size;
    int nb_decale;
    int cp_espace;

    for (size; 0 < size; --size) {
        cp_espace = espace;
        nb_decale = save_decale;
        for (nb_decale; nb_decale > 0; --nb_decale) {
            my_putchar(' ');
        }
        my_putchar('*');
        --save_decale;
        for (cp_espace; cp_espace > 0; --cp_espace) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
        espace += 2;
    }
}

void re_print_middle(int espace, int size)
{
    int save_decale = 1;
    int nb_decale;
    int cp_espace;

    save_decale = 1;
    for (size; 0 < size; --size) {
        cp_espace = espace;
        nb_decale = save_decale;
        for (nb_decale; nb_decale > 0; --nb_decale) {
            my_putchar(' ');
        }
        my_putchar('*');
        ++save_decale;
        for (cp_espace; cp_espace > 0; --cp_espace) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
        espace -= 2;
    }
}
