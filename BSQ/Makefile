##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/bsq.c	\
		src/get_map.c	\
		src/draw_square.c	\
		src/manage_square.c	\
		src/main.c \
		src/error_handling.c	\

SRC_units	=	src/bsq.c	\
				src/get_map.c	\
				src/draw_square.c	\
				src/manage_square.c	\
				src/error_handling.c	\
				tests/bsq_tests.c

NAME	=	bsq

CFFLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):
	make -C lib/my re
	gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy -g

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all

tests_run:	clean
		gcc -o unit_tests $(SRC_units) -I./include -L./lib -lmy $(CFFLAGS)
		./unit_tests
		rm unit_tests-*
