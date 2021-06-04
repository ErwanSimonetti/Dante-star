/*
** EPITECH PROJECT, 2021
** check_errors.c
** File description:
** returns 84 in case of error
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"

int check_errors(int ac)
{
    if (ac != 2)
        return (84);
    return (0);
}

int check_array_and_string(char **maze, int lines, int cols)
{
    for (int n = 0; maze[n] != NULL; n++) {
        for (int m = 0; maze[n][m] != '\0'; m++) {
            if (maze[n][m] != '*' && maze[n][m] != 'X' && maze[n][m] != '\n')
                return (84);
        }
    }
    if (maze[0][0] != '*' || maze[lines - 1][cols - 1] != '*')
        return (84);
    return (0);
}

bool check_array_exit(maze_t *maze_struct, int check_cols, int check_lines)
{
    if (check_cols >= 0 && check_cols < maze_struct->cols &&
    check_lines >= 0 && check_lines < maze_struct->lines &&
    maze_struct->maze[check_lines][check_cols] == '*')
        return (true);
    return (false);
}