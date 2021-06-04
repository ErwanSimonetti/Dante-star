/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main for generator
*/

#include "solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_curse_prgrm(maze_t *maze_struct, int check_cols, int check_lines)
{
    if (maze_struct->maze[maze_struct->lines - 1][maze_struct->cols - 1] == 'o')
        return 1;
    if (check_array_exit(maze_struct, check_cols, check_lines) == true) {
        maze_struct->maze[check_lines][check_cols] = 'o';
        if (my_curse_prgrm(maze_struct, check_cols + 1, check_lines) == 1)
            return 1;
        if (my_curse_prgrm(maze_struct, check_cols, check_lines + 1) == 1)
            return 1;
        if (my_curse_prgrm(maze_struct, check_cols - 1, check_lines) == 1)
            return 1;
        if (my_curse_prgrm(maze_struct, check_cols, check_lines - 1) == 1)
            return 1;
        maze_struct->maze[check_lines][check_cols] = '*';
        return 0;
    }
    return 0;
}

int create_maze_tab(char **av)
{
    char *map = open_and_read(av[1]);
    maze_t maze_struct = {0};
    int check_cols = 0;
    int check_lines = 0;
    
    maze_struct.maze = str_to_array(map);
    maze_struct.cols = strlen(maze_struct.maze[0]);
    maze_struct.lines = array_size(maze_struct.maze);
    if (check_array_and_string(maze_struct.maze, maze_struct.lines, maze_struct.cols) == 84) {
        printf("no solution found\n");
        return (84);
    }
    my_curse_prgrm(&maze_struct, check_cols, check_lines);
    print_map(maze_struct.maze);
    free_array(maze_struct.maze);
    free(map);
    return (0);
}

int main(int ac, char **av)
{
    if (check_errors(ac) == 84)
        return (84);
    else if (create_maze_tab(av) == 84)
        return (84);
    return (0);
}