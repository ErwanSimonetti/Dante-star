/*
** EPITECH PROJECT, 2021
** generator.c
** File description:
** generate maze
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"

void print_map(t_generator data)
{
    int count = 0;

    while (data.maze[count] != NULL) {
        if (data.maze[count + 1] != NULL)
            printf("%s\n", data.maze[count]);
        else
            printf("%s", data.maze[count]);
        count += 1;
    }
}

void generator(t_generator data)
{
    time_t timer = time(NULL);

    srand(timer);
    data.maze = fill_map(data);
    data.maze = build_perfect_maze(data);
    data.maze = replace_path(data);
    if (data.is_perfect != 1)
        data.maze = dig_random(&data);
    print_map(data);
    for (int n = 0; data.maze[n] != NULL; n++) {
        free(data.maze[n]);
    }
    free(data.maze);
}