##
## EPITECH PROJECT, 2021
## Graphical
## File description:
## Makefile
##

SRC	=	src/my_runner.c	\
		src/utils/utils_csfml.c	\
		src/events.c	\
		src/main.c	\
		src/lazer.c	\
		src/put_text.c \
		src/put_sprite.c	\
		src/collision.c	\
		src/inits.c	\
		src/missile.c	\
		src/move.c	\
		src/menu.c	\
		src/dead.c	\
		src/inits_obj/inits_obj.c	\
		src/inits_obj/inits_paralax.c	\
		src/inits_obj/inits_sprites.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CC	=	gcc -g

CSFML_FLAGS	=	-lcsfml-graphics    \
				-lcsfml-window    \
				-lcsfml-system    \
				-lcsfml-audio	\
				-lm

LIB	=	-I./include -L./lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(CSFML_FLAGS)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all clean