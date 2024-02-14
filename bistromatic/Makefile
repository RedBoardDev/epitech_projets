##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	main.c	\
		all_calc.c	\
		error_handling1.c	\
		error_handling2.c	\
		error_handling3.c	\
		eval_expr_inf.c	\
		eval_expr_int.c	\
		hub_evalexpr.c	\
		factory.c	\
		infin_add.c	\
		infin_calc.c	\
		infin_sub.c	\
		infin_utils.c	\
		is.c	\
		polish_converter.c	\


NAME	=	calc

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
