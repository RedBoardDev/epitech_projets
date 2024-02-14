##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

NAME	=	cesar

SRC	=	main.c	\
		my_str_isnum.c	\
		get_file.c	\
		decypher.c	\
		my_str_isalpha.c	\

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
