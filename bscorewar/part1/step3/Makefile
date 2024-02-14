##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME	=	write-a-number-as-int

# src file

SRC_FILES	=	main.c	\

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
