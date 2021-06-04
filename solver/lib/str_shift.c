/*
** EPITECH PROJECT, 2020
** str_shift
** File description:
** shift
*/

#include "../include/solver.h"
#include <unistd.h>
#include <stdio.h>

int my_strlenshift(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}

void str_shift(char **str, int n)
{
    str[0] = &str[0][n];
}
