/*
** EPITECH PROJECT, 2021
** get_generator_data.c
** File description:
** made to stock in struct data about generator
*/

#include "generator.h"
#include <string.h>
#include <stdlib.h>

char **malloc_maze(char **maze, int x, int y)
{
    int count = 0;

    maze = malloc(sizeof(char *) * (y + 1));
    while (count < y) {
        maze[count] = malloc(sizeof(char) * (x + 1));
        maze[count][x] = '\0';
        count += 1;
    }
    maze[count] = NULL;
    return (maze);
}

t_generator init_generator_data(int ac, char const *av[])
{
    t_generator returned = {0, 0, 0, 0, NULL, 0};

    returned.size_x = atoi(av[1]);
    returned.size_y = atoi(av[2]);
    returned.x = 0;
    returned.y = 0;
    returned.maze = malloc_maze(returned.maze,
    returned.size_x, returned.size_y);
    if (ac > 3 && strcmp("perfect", av[3]) == 0)
        returned.is_perfect = 1;
    else
        returned.is_perfect = 0;
    return (returned);
}