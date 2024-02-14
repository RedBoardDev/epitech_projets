##
## EPITECH PROJECT, 2021
## Graphical
## File description:
## Makefile
##

SRC	=	screensaver_1.c	\
		screensaver_2.c	\
		screensaver_3.c	\
		screensaver_4.c	\
		screensaver_5.c	\
		screensaver_6.c	\
		utils/utils_csfml.c   \
		utils/draw_utils.c	\
		utils/img_utils.c	\
		screensaver_main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

CSFML_FLAGS	=	-lcsfml-graphics    \
			-lcsfml-window    \
			-lcsfml-system    \
			-lcsfml-audio	\
			-lm

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g $(CSFML_FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all clean