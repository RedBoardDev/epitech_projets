##
## EPITECH PROJECT, 2023
## B-OOP-400-MLH-4-1-raytracer-leo.baldachino
## File description:
## Makefile
##

all: raytracer lights primitives

raytracer:
	make -C Core

lights:
	make -C Lights

primitives:
	make -C Primitives

clean:
	make clean -C Core
	make clean -C Primitives
	make clean -C Lights

fclean:
	make fclean -C Core
	make fclean -C Primitives
	make fclean -C Lights

re:	fclean all
