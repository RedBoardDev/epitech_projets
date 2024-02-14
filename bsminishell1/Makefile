##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/minishell1.c	\

# SRC_units	=	src/test.c	\

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

FLAGS = -Wall -Wextra -Werror

CFFLAGS	=	--coverage -lcriterion

LIB	=	-I./include -L./lib -lmy

BIN	=	vgcore*	\
		unit_tests-*

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
	make clean

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
			make -C lib/my
			gcc -o unit_tests $(SRC_UNITS) $(SRC_TEST) $(LIB) $(CFFLAGS)
			./unit_tests