##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME	=	yolotron-asm

# src file

SRC_FILES	=	main.c	\
				my_str_to_word_array.c	\

SRC	=	$(SRC_FILES)

# obj compilation and flags
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

BIN	=	vgcore*	\
		unit_tests-* \

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
