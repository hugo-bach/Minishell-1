/*
** EPITECH PROJECT, 2018
** my_macro.c
** File description:
** fct macro
*/

#include "my_shell.h"

int my_macro(int status)
{
    static int save = 0;
    int temp = 0;

    temp = save;
    save = status;
    return (temp);
}
