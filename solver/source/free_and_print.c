/*
** EPITECH PROJECT, 2021
** maze
** File description:
** print
*/

#include <stdlib.h>
#include <stdio.h>

void print_map(char **maze)
{
    for (int curs = 0; maze[curs] != NULL; ++curs) {
        if (maze[curs + 1] != NULL)
            printf("%s\n", maze[curs]);
        if (maze[curs + 1] == NULL)
            printf("%s", maze[curs]);
    }
}

void free_array(char **maze)
{
    for(int n = 0; maze[n] != NULL; n++) {
        free(maze[n]);
    }
    free(maze);
}