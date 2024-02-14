##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	z

SRC	=	z.c

# compilation
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

# clean file
BIN	=	vgcore*	\
		unit_tests*	\

# flags
FLAGS	=	-I./include	\
		-g	\

CFLAGS	+=	-Werror	\
			-Wextra	\
			-Wall	\

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -ne "\033[1;34m=============== Files compilation ok ============="
	@echo -e "\033[0m"
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)
	@echo -ne "\033[1;32m=============== Compilation done ================="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	@echo -ne "\033[1;33m=============== Cleaning done ===================="
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME)
	@echo -ne "\033[1;33m=============== Full cleaning done ==============="
	@echo -e "\033[0m"

re:	fclean all

.PHONY:		all clean fclean re exec
