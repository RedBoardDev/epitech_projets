/*
** EPITECH PROJECT, 2021
** Star project
** File description:
** Main star display
*/

void print_star_size1_flat(void)
{
    my_putchar('\n');
    for (int i = 0; i < 3; i++) {
        my_putchar('*');
    }
    my_putchar(' ');
    for (int i = 0; i < 3; i++) {
        my_putchar('*');
    }
    my_putchar('\n');
}

void print_star_size1_points(void)
{
    for (int i = 0; i < 3; i++) {
        my_putchar(' ');
    }
    my_putchar('*');
}

void print_star_size1(void)
{
    print_star_size1_points();
    print_star_size1_flat();
    my_putchar(' ');
    my_putchar('*');
    for (int i = 0; i < 3; i++) {
        my_putchar(' ');
    }
    my_putchar('*');
    print_star_size1_flat();
    print_star_size1_points();
}

void star(unsigned int size)
{
    int cursor;
    int espace;
    int save;
    int espace_flat;

    if (size <= 0) {
        return (0);
    } else if (size == 1) {
    print_star_size1();
    } else {
        cursor = (size * 3) - 1;
        espace = -1;
        save = size;
        espace = calcul_funct_top(save, cursor, espace);
        espace = calcul_middle(espace_flat, espace, size);
        cursor = (size*2);
        calcul_bottom(save, cursor, espace);
    }
}
