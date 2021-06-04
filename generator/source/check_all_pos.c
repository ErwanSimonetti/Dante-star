/*
** EPITECH PROJECT, 2021
** check
** File description:
** pos
*/

#include <stdlib.h>
#include <string.h>
#include "generator.h"

bool check_all_pos(t_generator *data)
{
    for (int n = 0; data->maze[n] != NULL; n++) {
        for (int m = 0; data->maze[n][m] != '\0'; m++) {
            if (n % 2 == 0 && m % 2 == 0 && data->maze[n][m] != '1' && data->maze[n][m] != '2'
            && data->maze[n][m] != '*')
                return (false);
        }
    }
    return (true);
}