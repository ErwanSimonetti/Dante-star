##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makes binary and more
##

SRC				=		source/check_errors.c			\
						source/init_generator_data.c	\
						source/generator_error.c 		\
						source/fill_map.c 				\
						source/build_imperfect_maze.c 	\
						source/build_perfect_maze.c 	\
						source/imperfect_done.c 		\
						source/replace_path.c 			\
						source/rand_generator.c 		\
						source/backtrack.c 				\
						source/generator.c				\
						source/dig_random.c 			\
						source/check_all_pos.c

NAME			=		generator

CFLAGS          =       -Wall -Wextra -pedantic

CPPFLAGS        =       -I./include

CC 				=		gcc

all:	binary

binary:
		$(CC) -o $(NAME) $(SRC) main.c $(CPPFLAGS) $(CFLAGS) -g3
		echo -e "\033[05m\033[44mcompilation done => ${NAME}\033[00m"

clean:
		rm -f *.c~

fclean:	clean
		rm -f $(NAME)
		clear

re:	fclean all

.PHONY:	clean fclean re all binary
