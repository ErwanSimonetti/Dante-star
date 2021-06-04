/*
** EPITECH PROJECT, 2021
** maze
** File description:
** size
*/

#include <stdio.h>
#include <stdlib.h>

int array_size(char **array)
{
    int n = 0;

    for (; array[n] != NULL; ++n);
    return (n);
}