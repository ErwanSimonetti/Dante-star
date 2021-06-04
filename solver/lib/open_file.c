/*
** EPITECH PROJECT, 2020
** open
** File description:
** file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

static int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        return (84);
    }
    else
        return (fd);
}

static int fs_understand_return_of_read(int fd, char *buffer, int  size)
{
    int rd = read(fd, buffer, size);

    if (rd == -1)
        return (84);
    if (rd == 0)
        return (84);
    if (rd < size)
        return (84);
    if (rd > size)
        return (84);
    else
        return (0);
}

static long int find_buff(char const *filepath)
{
    struct stat buffer;

    if (stat(filepath, &buffer) == -1)
        return (84);
    return (buffer.st_size);
}

char *open_and_read(char const *str)
{
    int fd = 0;
    long int x = 0;
    char *buffer = NULL;
    int rd = 0;

    fd = fs_open_file(str);
    if (fd == 84)
        exit(84);
    x = find_buff(str);
    if (x == 84)
        exit(84);
    buffer = malloc(sizeof(char) * (x + 1));
    if (buffer == NULL)
        exit(84);
    buffer[x] = '\0';
    rd = fs_understand_return_of_read(fd, buffer, x);
    if (rd == 84)
        exit(84);
    return (buffer);
} 
