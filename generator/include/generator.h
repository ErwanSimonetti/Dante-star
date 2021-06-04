/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-martin.blancho
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <stdbool.h>

typedef struct generator_structure
{
    int size_x;
    int size_y;
    int x;
    int y;
    char **maze;
    int is_perfect;
}t_generator;

t_generator init_generator_data(int ac, char const *av[]);
void generator(t_generator data);
int check_errors(int ac, char const *av[]);
int generator_errors(int ac, const char *av[]);
char **fill_map(t_generator data);
char **build_imperfect_maze(t_generator data);
char **build_perfect_maze(t_generator data);
int imperfect_done(t_generator data);
void print_map(t_generator data);
char **replace_path(t_generator data);
int rand_generator(int minimum, int maximum);
void backtrack(t_generator *data);
int is_writable_perfect(t_generator *data, int axis, int direction);
int find_direction(int next_pos);
bool check_all_pos(t_generator *data);
char **dig_random(t_generator *data);

#endif /* !GENERATOR_H_ */
