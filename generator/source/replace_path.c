/*
** EPITECH PROJECT, 2021
** replace_path.c
** File description:
** made to replace path with good chars
*/

#include "generator.h"
#include <stddef.h>

char *replace_line(char *current_line)
{
    int count = 0;

    while (current_line[count] != '\0') {
        if (current_line[count] == '1' || current_line[count] == '2')
            current_line[count] = '*';
        count += 1;
    }
    return (current_line);
}

char **replace_path(t_generator data)
{
    int count = 0;

    while (data.maze[count] != NULL) {
        data.maze[count] = replace_line(data.maze[count]);
        count += 1;
    }
    return (data.maze);
}