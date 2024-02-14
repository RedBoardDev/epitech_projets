/*
** EPITECH PROJECT, 2021
** MY_PRINT_ALPHA
** File description:
** print alphabet
*/

int my_print_alpha(void)
{
    int letter_ascii;
    letter_ascii = 97;
    while   (letter_ascii < 123) {
        my_putchar(letter_ascii);
        ++letter_ascii;
    }
    return  (0);
}
