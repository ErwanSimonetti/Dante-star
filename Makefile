##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makes binary and more
##

all:
		make -C generator/
		make -C solver/

clean:
		make -C generator/ clean
		make -C solver/ clean

fclean:	clean
		make -C generator/ fclean
		make -C solver/ fclean
		clear

re:	fclean all

.PHONY:	clean fclean re all
