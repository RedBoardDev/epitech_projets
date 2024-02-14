/*
** EPITECH PROJECT, 2021
** MY_PRINT_REVALPHA
** File description:
** print reverse alphabet
*/

int my_print_revalpha(void)
{
    int letter_ascii;
    letter_ascii = 122;
    while   (letter_ascii > 96) {
        my_putchar(letter_ascii);
        letter_ascii--;
    }
    return  (0);
}
