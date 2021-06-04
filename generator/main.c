/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main for generator
*/

#include "generator.h"

int main(int ac, char const *av[])
{
    t_generator data;

    if (generator_errors(ac, av) == 84)
        return (84);
    else {
        data = init_generator_data(ac, av);
        generator(data);
        return (0);
    }
}