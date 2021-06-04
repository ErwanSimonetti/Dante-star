/*
** EPITECH PROJECT, 2021
** build_maze.c
** File description:
** made to build perfect maze
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"

int find_direction(int next_pos)
{
    if (next_pos == 1 || next_pos == 2)
        return (-1);
    else
        return (1);
}

static int is_writable(t_generator *data, int axis, int direction)
{
    if (axis == 1) {
        if (data->x + 2 * direction >= 0 &&
        data->x + 2 * direction < data->size_x + 1)
            return (1);
        else
            return (0);
    }
    if (axis == 2) {
        if (data->y + 2 * direction >= 0 &&
        data->y + 2 * direction < data->size_y + 1)
            return (1);
        else
            return (0);
    }
    return (0);
}

static void build_imperfect_line(t_generator *data)
{
    int next_pos = rand_generator(1, 4);
    int axis = rand_generator(1, 2);
    int direction = find_direction(next_pos);
    int count = 0;

    while (count < 2) {
        if (axis == 1 && is_writable(data, axis, direction)) {
            data->maze[data->y][data->x + direction] = '1';
            data->x += direction;
        } else if (axis == 1 && is_writable(data, axis, direction * (-1))) {
            data->maze[data->y][data->x - direction] = '1';
            data->x -= direction;
        } else
            axis = 2;
        if (axis == 2 && is_writable(data, axis, direction)) {
            data->maze[data->y + direction][data->x] = '1';
            data->y += direction;
        } else if (axis == 2 && is_writable(data, axis, direction * (-1))){
            data->maze[data->y - direction][data->x] = '1';
            data->y -= direction;
        }
        count += 1;
    }
}

char **build_imperfect_maze(t_generator data)
{
    int count = 0;

    while (imperfect_done(data) != 1) {
        build_imperfect_line(&data);
        count += 1;
    }
    return (data.maze);
}