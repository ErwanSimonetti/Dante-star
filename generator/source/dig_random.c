/*
** EPITECH PROJECT, 2021
** dig_random.C
** File description:
** imperfect
*/

#include "generator.h"

char **dig_random(t_generator *data)
{
    int to_dig = rand_generator(5, data->size_x + data->size_y);
    int count = 0;
    int x = rand_generator(1, data->size_x - 1);
    int y = rand_generator(1, data->size_y - 1);

    while (count != to_dig) {
        x = rand_generator(1, data->size_x - 1);
        y = rand_generator(1, data->size_y - 1);
        if (data->maze[y][x] == 'X')
            data->maze[y][x] = '*';
        else data->maze[y][x - 1] = '*';
        count += 1;
    }
    return (data->maze);
}