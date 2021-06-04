/*
** EPITECH PROJECT, 2021
** backtrack.c
** File description:
** made to go back to a previous maze location
*/

#include "generator.h"
#include <unistd.h>
#include <stdio.h>

static int is_cornered(t_generator *data)
{
    if (is_writable_perfect(data, 1, 1) == 0
    && is_writable_perfect(data, 2, 1) == 0
    && is_writable_perfect(data, 1, -1) == 0
    && is_writable_perfect(data, 2, -1) == 0) {
        return (1);
    }
    return (0);
}

static void write_two(t_generator *data, int count)
{
    if (is_cornered(data) || count == 0)
        data->maze[data->y][data->x] = '2';
}

static int find_new_path(t_generator *da)
{
    if (da->x + 2 < da->size_x + 1 && da->maze[da->y][da->x + 2] == 'X') {
        da->x += 1;
        da->maze[da->y][da->x] = '2';;
        return (1);
    } else if (da->x - 2 >= 0 && da->maze[da->y][da->x - 2] == 'X') {
        da->x -= 1;
        da->maze[da->y][da->x] = '2';;
        return (1);
    } else if (da->y + 2 < da->size_y - 1 && da->maze[da->y + 2][da->x] == 'X') {
        da->y += 1;
        da->maze[da->y][da->x] = '2';;
        return (1);
    } else if (da->y - 2 >= 0 &&
    da->maze[da->y - 2][da->x] == 'X') {
        da->y -= 1;
        da->maze[da->y][da->x] = '2';;
        return (1);
    }
    return (0);
}

static void go_back(t_generator *data)
{
    int count = 0;

    data->maze[data->y][data->x] = '2';;
    while (count != 2) {
        if (data->maze[data->y][data->x + 1] == '1') {
            data->x += 1;
            write_two(data, count);
        } else if (data->y + 1 < data->size_y - 1 &&
        data->maze[data->y + 1][data->x] == '1') {
            data->y += 1;
            write_two(data, count);
        } else if (data->maze[data->y][data->x - 1] == '1') {
            data->x -= 1;
            write_two(data, count);
        } else if (data->maze[data->y - 1][data->x] == '1') {
            data->y -= 1;
            write_two(data, count);
        } else
            find_new_path(data);
        count += 1;
    }
}

void backtrack(t_generator *data)
{
    go_back(data);
}