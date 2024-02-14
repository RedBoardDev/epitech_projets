##
## EPITECH PROJECT, 2021
## B-CPE-101-MLH-1-1-infinadd-martin.d-herouville
## File description:
## Makefile
##

SRC	=	evalexpr.c	\
		factory.c	\
		is.c	\
		polonish_converter.c

##OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

all:	$(NAME)

$(NAME):	##$(OBJ)
	make -C lib/my re
	gcc -o $(NAME) *.c -I./include -L./lib -lmy

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
