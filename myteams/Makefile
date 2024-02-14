##
## EPITECH PROJECT, 2022
## B-NWP-400-MLH-4-1-myteams-luca.haumesser
## File description:
## Makefile
##

all:
	make -C server
	mv server/myteams_server .
	make -C cli
	mv cli/myteams_cli .

re:
	make re -C server
	mv server/myteams_server .
	make re -C cli
	mv cli/myteams_cli .

clean:
	make clean -C server
	make clean -C cli

fclean:
	make fclean -C server
	make fclean -C cli
	rm -f myteams_server
	rm -f myteams_cli
