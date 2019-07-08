/*
** EPITECH PROJECT, 2018
** my_calloc.c
** File description:
** fct calloc for char *
*/

#include "my_shell.h"

char *my_calloc(int size)
{
    char *result = malloc(sizeof(char) * (size + 1));

    if (result == NULL)
        exit (8);
    for (int i = 0; i <= size; i++)
        result[i] = '\0';
    return (result);
}
