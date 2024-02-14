##
## EPITECH PROJECT, 2021
## B-PSU-100-MLH-1-1-myls-thomas.ott
## File description:
## Makefile
##

SRC	=	src/my_ls.c	\
		src/flag_l.c	\
		src/print_final.c	\
		src/get_info.c	\

# SRC_units	=	src/bsq.c	\
# 				src/get_map.c	\
# 				src/draw_square.c	\
# 				src/manage_square.c	\
# 				src/error_handling.c	\
# 				tests/bsq_tests.c

NAME	=	my_ls

CFFLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):
	make -C lib/my re
	gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all clean

tests_run:	clean
		gcc -o unit_tests $(SRC_units) -I./include -L./lib -lmy $(CFFLAGS)
		./unit_tests
		rm unit_tests-*
