##
## EPITECH PROJECT, 2021
## Makefile Projet
## File description:
## Makefile
##

all:
	make -C antman
	make -C giantman

clean:
	make -C antman clean
	make -C giantman clean
	make -C lib/my clean

fclean:	clean
	make -C antman fclean
	make -C giantman fclean
	make -C lib/my fclean

re:	fclean all

gcovr:
	make -C antman gcovr
	make -C giantman gcovr

tests_run:
	make -C antman tests_run
	make -C giantman tests_run
