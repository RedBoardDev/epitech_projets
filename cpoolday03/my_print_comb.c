/*
** EPITECH PROJECT, 2021
** MY_PRINT_COMB
** File description:
** display three different digits numbers
*/

void my_print_putchar(int a, int b, int c)
{
    my_putchar(a + '0');
    my_putchar(b + '0');
    my_putchar(c + '0');
    if (!(a == 7 && b == 8 && c == 9)) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int last_condition(int a, int b, int c)
{
    while   (c <= 9) {
        my_print_putchar(a, b , c);
        c = c + 1;
    }
}

int my_print_comb(void)
{
    int a;
    int b;
    int c;

    a = 0;
    while   (a <= 7) {
        b = a + 1;
        while   (b <= 8) {
            c = b + 1;
            c = last_condition(a, b, c);
            b = b + 1;
        }
        a = a + 1;
    }
    my_putchar('\n');
}
