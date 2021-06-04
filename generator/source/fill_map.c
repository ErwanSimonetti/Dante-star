/*
** EPITECH PROJECT, 2021
** fill_map.c
** File description:
** made to fill the maze
*/

#include "generator.h"
#include <stdio.h>

char *fill_line(int x, char *line)
{
    int count = 0;

    while (count != x) {
        line[count] = 'X';
        count += 1;
    }
    return (line);
}

char **fill_map(t_generator data)
{
    int count = 0;

    while (data.maze[count] != NULL) {
        data.maze[count] = fill_line(data.size_x, data.maze[count]);
        count += 1;
    }
    data.maze[0][0] = '*';
    data.maze[data.size_y - 1][data.size_x - 1] = '*';
    count = 0;
    return (data.maze);
}