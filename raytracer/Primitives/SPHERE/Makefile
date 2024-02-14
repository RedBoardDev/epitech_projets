##
## EPITECH PROJECT, 2023
## B-OOP-400-MLH-4-1-raytracer-leo.baldachino
## File description:
## Makefile
##

SRC	=	src/Sphere.cpp

NAME = 	../../plugins/raytracer_sphere.so

all:	$(NAME)

$(NAME):	$(SRC)
	g++ -o $(NAME) $(SRC) -shared -fPIC

fclean:
	rm -f $(NAME)

re: fclean all
