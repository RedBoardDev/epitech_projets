##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

re_test: graphicals_re games_re
	make re -C Test

test: graphicals games
	make -C Test

graphicals:
	make -C Graphicals

graphicals_clean:
	make clean -C Graphicals

graphicals_fclean:
	make fclean -C Graphicals

graphicals_re:
	make re -C Graphicals

games:
	make -C Games

games_clean:
	make clean -C Games

games_fclean:
	make fclean -C Games

games_re:
	make re -C Games

core:
	make -C Core

core_clean:
	make clean -C Core

core_fclean:
	make fclean -C Core

core_re:
	make re -C Core

all: graphicals games core

clean: graphicals_clean games_clean core_clean

fclean: graphicals_fclean games_fclean core_fclean
	rm -rf test

re:	graphicals_re games_re core_re