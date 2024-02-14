##
## EPITECH PROJECT, 2021
## Makefile Projet
## File description:
## Makefile
##

SRC	=	src/pushswap.c	\
		src/operations.c	\
		src/lib_list/add_node.c	\
		src/lib_list/general_list.c	\
		src/lib_list/remove_node.c	\
		src/main.c	\

SRC_UNITS	=	src/pushswap.c	\
				src/operations.c	\
				src/lib_list/add_node.c	\
				src/lib_list/general_list.c	\
				src/lib_list/remove_node.c	\

SRC_TEST	=	tests/test.c	\

NAME	=	push_swap

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
		gcc -o unit_tests $(SRC_UNITS) $(SRC_TEST) $(LIB) $(CFFLAGS)
		./unit_tests
