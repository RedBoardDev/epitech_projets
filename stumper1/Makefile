##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

NAME	=	fractals

SRC	=	main.c	\
		my_atoi.c	\
		my_strlen.c	\
		fractal.c	\
		string_params.c	\
# obj compilation and flags
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

FLAGS = -Wall \
		-Wextra \
		-Werror \

BIN	=	vgcore*	\

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

