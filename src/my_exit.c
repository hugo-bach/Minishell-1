/*
** EPITECH PROJECT, 2018
** my_exit.c
** File description:
** fct who exit the process
*/

#include "my_shell.h"

void my_exit(mshell_l *sh)
{
    for (int i = 0; sh->env[i]; i++)
        free (sh->env[i]);
    free (sh->env);
    if (sh->arg != NULL) {
        for (int i = 0; sh->arg[i]; i++)
            free (sh->arg[i]);
        free (sh->arg);
    }
    if (sh->oldpath != NULL)
        free (sh->oldpath);
    exit (0);
}
