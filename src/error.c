/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** fct who treat all error of my minishell
*/

#include "my_shell.h"

void error_erno(char *str, int erno)
{
    char *result = strerror(erno);
    write(1, str, my_strlen(str));
    write(1, ": ", 2);
    write(1, result, my_strlen(result));
    write(1, ".\n", 2);
}
