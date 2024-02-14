##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

NAME	=	boggle

SRC	=	boggle_flags.c	\
		my_atoi.c	\
		my_strcmp.c	\
		my_is.c	\
		my_str_isnum.c	\
		my_str_isstr.c	\
		my_strlen.c	\
		main.c		\
		find_word.c	\

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
