/*
** EPITECH PROJECT, 2021
** rand_generator.c
** File description:
** made to generate random nb
*/

#include <stdlib.h>
#include "generator.h"

int rand_generator(int minimum, int maximum)
{
    int rand_nb = rand() % maximum + minimum;

    return (rand_nb);
}