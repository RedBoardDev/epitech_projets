/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Rush1-3
*/

void print_line_middle(int a, int b, int bool)
{
    if (bool == 1) {
        for (int i = b - 2;0 < i; --i) {
            my_putchar('B');
            for (int i = a - 2; 0 < i; --i) {
                my_putchar(' ');
            }
            if  (a != 1) {
                my_putchar('B');
            }
            my_putchar('\n');
        }
    } else {
        my_putchar('A');
        for (a; 0 < a - 2; --a) {
            my_putchar('B');
        }
        my_putchar('A');
        my_putchar('\n');
    }
}

void print_line_modified(int a)
{
    my_putchar('C');
    for (a; 0 < a - 2; --a) {
        my_putchar('B');
    }
    my_putchar('C');
    my_putchar('\n');
}

int print_ligne(a, b)
{
    if (b == 1){
        for (int i = a; 0 < i; --i) {
            my_putchar('B');
        }
    }
    if  (b != 1) {
        print_line_middle(a, b, 1);
    } else
        print_line_middle(a, b - 1, 1);
    if  (a == 1) {
        my_putchar('B');
    } else if  (b != 1)
        print_line_modified(a);
}

void rush(int a, int b)
{
    if  (a <= 0 || b <= 0) {
        write(2, "Invalid size\n", 13);
        return  (0);
    }
    if  (a == 1 && b == 1) {
        my_putchar('B');
    } else {
        if  (a == 1) {
            my_putchar('B');
            my_putchar('\n');
        } else if (b != 1 ){
            print_line_middle(a, b, 0);
        }
        print_ligne(a, b);
    }
}
