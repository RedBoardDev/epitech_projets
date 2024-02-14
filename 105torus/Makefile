##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/print_help.c	\

# SRC_TESTS	=	tests/tests_advanced.c	\
# 			tests/tests_convert.c	\
# 			tests/tests_simple.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

NAME	=	105torus

NAME_TESTS	=	unit_tests

BIN	=	vgcore*	\
		unit_tests*	\

FLAGS	=	-I./include	\
		-L./lib	\
		-lmy	\
		-g	\

WFLAGS	=	-Wall	\
			-Werror	\
			-Wextra	\

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

exec:	re
	@echo
	@echo "-------------------------------------------------"
	@echo
	@./$(NAME)

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
		make -C lib/my
		gcc -o $(NAME_TESTS) $(SRC) $(SRC_TESTS) --coverage -lcriterion
		./$(NAME_TESTS)
