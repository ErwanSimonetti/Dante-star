/*
** EPITECH PROJECT, 2021
** bs
** File description:
** bs
*/

#include "../include/solver.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int char_counter(char *str, char a)
{
    int n = 1;
    int cur = 0;

    while (str[cur] != '\0') {
        if (str[cur] == a)
            n++;
        cur++;
    }
    return (n);
}

char **str_to_array(char *str)
{
    int space_nb = char_counter(str, '\n');
    char **av = malloc(sizeof(char *) * (space_nb + 1));
    int o = 0;
    int c = 0;
    int j = 0;

    for (int n = 0; j < space_nb; j++, o++) {
        c =  my_strlenshift(str);
        av[o] = malloc(sizeof(char) * c + 1);
        while (n <= c - 1) {
            av[o][n] = str[n];
            n++;
        }
        av[o][n] = '\0';
        n = 0;
        str_shift(&str, c + 1);
        c = 0;
    }
    av[space_nb] = NULL;
    return (av);
}