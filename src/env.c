/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** fct who display my_env
*/

#include "my_shell.h"

int my_strlen(char *str)
{
    int nb = 0;

    for (; str[nb]; nb++);
    return (nb);
}

void my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
}
