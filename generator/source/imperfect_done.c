/*
** EPITECH PROJECT, 2021
** imperfect_done.c
** File description:
** returns true if imperfect map is done
*/

#include "generator.h"

int imperfect_done(t_generator data)
{
    if (data.maze[data.size_y - 1][data.size_x - 1] == '1'
    || data.maze[data.size_y - 2][data.size_x - 1] == '1'
    || data.maze[data.size_y - 1][data.size_x - 2] == '1')
        return (1);
    else
        return (0);
}