##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/my_printf.c	\
		src/my_put_nbr.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/function_flags.c	\
		src/my_convert_base.c	\
		src/my_strlen.c	\
		src/function_flags2.c

TEST	=	tests/test_util1.c	\
			tests/test_len.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFFLAGS	=	tests/test_util1.c -I./include --coverage -lcriterion

libmy.a: all

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f unit_tests*

re:	all clean

unit_tests:
		$(CC) -o unit_tests src/*.c $(CFFLAGS)

tests_run:	re
			make unit_tests
	./unit_tests
