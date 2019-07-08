/*
** EPITECH PROJECT, 2018
** my_strcalloc.c
** File description:
** fct calloc for char **
*/

#include "my_shell.h"

char **my_strcalloc(int size)
{
    char **result = malloc(sizeof(char *) * (size + 1));

    if (result == NULL)
        exit (4);
    for (int i = 0; i <= size; i++)
        result[i] = NULL;
    return (result);
}
