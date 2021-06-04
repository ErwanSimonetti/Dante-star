##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makes binary and more
##

SRC				=		source/check_errors.c	\
						lib/open_file.c			\
						lib/str_shift.c			\
						lib/str_to_array.c		\
						lib/array_size.c		\
						source/free_and_print.c

NAME			=		solver

CFLAGS          =       -Wall -Wextra -pedantic

CPPFLAGS        =       -I./include

CC 				=		gcc

all:	binary

binary:
		$(CC) -o $(NAME) $(SRC) main.c $(CPPFLAGS) $(CFLAGS) -g3
		@echo -e "\033[05m\033[44mcompilation done => ${NAME}\033[00m"

clean:
		rm -f *.c~

fclean:	clean
		rm -f $(NAME)
		clear

re:	fclean all

.PHONY:	clean fclean re all binary
