##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/print_help.c	\
		src/sphere.c	\
		src/cylinder.c	\
		src/cone.c	\

# SRC_TESTS	=	tests/tests_advanced.c	\
# 			tests/tests_convert.c	\
# 			tests/tests_simple.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

NAME	=	104intersection

NAME_TESTS	=	unit_tests

BIN	=	vgcore*	\
		unit_tests*	\

FLAGS	=	-I./include	\
		-lm	\
		-g	\

WFLAGS	=	-Wall	\
			-Werror	\
			-Wextra	\

CSFML_FLAGS	=	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS)

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
