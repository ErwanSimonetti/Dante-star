/*
** EPITECH PROJECT, 2021
** build_perfect_maze.c
** File description:
** blank
*/

#include <stdio.h>
#include "generator.h"

int is_writable_perfect(t_generator *data, int axis, int direction)
{
    if (axis == 1) {
        if (data->x + 2 * direction == 0 && data->y == 0)
            return (0);
        if (data->x + 2 * direction >= 0 &&
        data->x + 2 * direction < data->size_x
        && data->maze[data->y][data->x + 1 * direction] != '1'
        && data->maze[data->y][data->x + 2 * direction] != '1'
        && data->maze[data->y][data->x + 1 * direction] != '2'
        && data->maze[data->y][data->x + 2 * direction] != '2')
            return (1);
        else
            return (0);
    } if (axis == 2) {
        if (data->x == 0 && data->y + 2 * direction == 0)
            return (0);
        if (data->y + 2 * direction >= 0 &&
        data->y + 2 < data->size_y
        && data->maze[data->y + 1 * direction][data->x] != '1'
        && data->maze[data->y + 2 * direction][data->x] != '1'
        && data->maze[data->y + 1 * direction][data->x] != '2'
        && data->maze[data->y + 2 * direction][data->x] != '2')
            return (1);
        else
            return (0);
    }
    return (0);
}

static int build_perfect_line(t_generator *data)
{
    int next_pos = rand_generator(1, 4);
    int axis = rand_generator(1, 2);
    int direction = find_direction(next_pos);

    if (data->x + 1 == data->size_x - 1 && data->y + 1 == data->size_y - 1) {
        data->maze[data->y][data->x + 1] = '2';
        backtrack(data);
        return (1);
    } if (axis == 1 && is_writable_perfect(data, axis, direction)) {
        data->maze[data->y][data->x + direction] = '1';
        data->maze[data->y][data->x + 2 * direction] = '1';
        data->x += 2 * direction;
        return (1);
    } else if (axis == 1 && is_writable_perfect(data, axis, direction * (-1))) {
        data->maze[data->y][data->x - direction] = '1';
        data->maze[data->y][data->x - 2 * direction] = '1';
        data->x -= 2 * direction;
        return (1);
    }
    else
        axis = 2;
    if (axis == 2 && is_writable_perfect(data, axis, direction)) {
        data->maze[data->y + direction][data->x] = '1';
        data->maze[data->y + 2 * direction][data->x] = '1';
        data->y += 2 * direction;
        return (1);
    } else if (axis == 2 && is_writable_perfect(data, axis, direction * (-1))){
        data->maze[data->y - direction][data->x] = '1';
        data->maze[data->y - 2 * direction][data->x] = '1';
        data->y -= 2 * direction;
        return (1);
    } else
        backtrack(data);
    return (0);
}

char **build_perfect_maze(t_generator data)
{
    while (check_all_pos(&data) == false)
        build_perfect_line(&data);
    return (data.maze);
}