##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

all:
	make -C generator
	make -C solver

clean:
	make -C solver clean
	make -C generator clean

fclean:	clean
	make -C solver fclean
	make -C generator fclean

re:	fclean all

.PHONY:		all clean fclean re exec gcovr tests_run
