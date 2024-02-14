##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	main.c	\

# SRC_TESTS	=	tests/tests_advanced.c	\
# 			tests/tests_convert.c	\
# 			tests/tests_simple.c	\

# OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

NAME_TESTS	=	unit_tests

BIN	=	vgcore*	\
		unit_tests*	\

FLAGS	=	-I./include	\
			-g	\
			-lm

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAGS)

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
		gcc -o $(NAME_TESTS) $(SRC) $(SRC_TESTS) --coverage -lcriterion
		./$(NAME_TESTS)
