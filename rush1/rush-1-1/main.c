/*
** EPITECH PROJECT, 2021
** main
** File description:
** Rush1-1
*/

void print_line_top(int a)
{
    if (a != 1) {
        my_putchar('o');
    }
    
    for (a; 0 < a - 2; --a) {
        my_putchar('-');
    }
    my_putchar('o');
    my_putchar('\n');
}

void print_line_middle(int a, int b)
{
    for (int i = b - 2; 0 < i; --i) {
        my_putchar('|');
        for (int i = a - 2; 0 < i; --i) {
            my_putchar(' ');
        }
        if  (a != 1) {
            my_putchar('|');
        }
        my_putchar('\n');
    }
}

void my_putcharT()
{
    my_putchar('o');
    my_putchar('\n');
}

void rush(unsigned int a, unsigned int b)
{
    if  (a <= 0 || b <= 0) {
        write(2, "Invalid size\n", 13);
        return  (0);
    }
    if  (a == 1 && b == 1) {
        my_putchar('o');
    } else {
        if  (a == 1) {
            my_putcharT();
        } else
            print_line_top(a);
        if  (b != 1) {
            print_line_middle(a, b);
        } else
            print_line_middle(a, b - 1);
        if  (b != 1) {
            print_line_top(a);
        }
    }
}
