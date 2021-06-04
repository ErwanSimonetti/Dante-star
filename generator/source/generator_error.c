/*
** EPITECH PROJECT, 2021
** generator
** File description:
** error
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool check_number(const char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < '0' || str[a] > '9')
            return (false);
    }
    return (true);
}

int generator_errors(int ac, const char *av[])
{
    if (ac != 3 && ac != 4) {
        fprintf(stderr, "Error: wrong number of arguments\n");
        return (84);
    }
    else if (check_number(av[1]) == false || check_number(av[2]) == false) {
        fprintf(stderr, "Error: arguments are not numbers\n");
        return (84);
    }
    else if (atoi(av[1]) < 6 || atoi(av[2]) < 6)
        return (84);
    return (0);
}