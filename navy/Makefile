##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/check_win.c	\
		src/game_play.c	\
		src/game_wait.c	\
		src/handlers_sig.c	\
		src/main.c	\
		src/mystrlen_custom.c	\
		src/navy.c	\
		src/print_beginning.c	\
		src/print_help.c	\
		src/print.c	\
		src/set_map.c	\
		src/inits_var.c	\
		src/error_boats.c	\
		src/error_handling.c	\
		src/set_vector_map.c	\

SRC_UNITS	=	src/check_win.c	\
			src/game_play.c	\
			src/game_wait.c	\
			src/handlers_sig.c	\
			src/mystrlen_custom.c	\
			src/navy.c	\
			src/print_beginning.c	\
			src/print_help.c	\
			src/print.c	\
			src/set_map.c	\
			src/inits_var.c	\
			src/error_boats.c	\
			src/error_handling.c	\
			src/set_vector_map.c	\

SRC_TEST	=	tests/test.c	\

NAME	=	navy

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
