/*
** EPITECH PROJECT, 2018
** my_path.c
** File description:
** fct who treat the path of env
*/

#include "my_shell.h"

int size_path(char *path)
{
    int nb = 1;

    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == ':')
            nb++;
    return (nb);
}

char **parsing_path(char *path)
{
    int i = 0;
    int nb = 0;
    char **result = my_strcalloc(size_path(path));

    for (i = 0; path[i] && path[i] != '/'; i++);
    for (int j = 0; path[i] != '\0'; j++) {
        for (int p = i; path[p] && path[p] != ':'; nb++, p++);
        result[j] = my_calloc(nb);
        nb = 0;
        for (int x = 0; path[i] && path[i] != ':'; x++, i++)
            result[j][x] = path[i];
        (path[i] != '\0') ? i++ : 0;
    }
    return (result);
}
