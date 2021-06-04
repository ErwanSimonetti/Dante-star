/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-martin.blancho
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <stdbool.h>

typedef struct maze_s
{
    char **maze;
    int lines;
    int cols;
} maze_t;

int check_errors(int ac);
char *open_and_read(char const *str);
void str_shift(char **str, int n);
int my_strlenshift(char const *str);
char **str_to_array(char *str);
int array_size(char **array);
int check_array_and_string(char **maze, int lines, int cols);
bool check_array_exit(maze_t *maze_struct, int check_cols, int check_lines);
void free_array(char **maze);
void print_map(char **maze);

#endif /* !GENERATOR_H_ */
