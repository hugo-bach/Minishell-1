/*
** EPITECH PROJECT, 2018
** my_strlen_str.c
** File description:
** my_strlen for char **
*/

#include "my_shell.h"

int my_strlen_str(char **str)
{
    int nb = 0;

    for (; str[nb] != NULL; nb++);
    return (nb);
}
