##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_str_to_word_array.c	\
		my_show.c	\
		src/my_putchar.c	\
		src/my_putstr.c     \
		src/my_strlen.c    \

NAME	=	sort_words

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

FLAGS = -Wall -Wextra -Werror

BIN	=	vgcore*	\
		unit_tests-*

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	make clean
