/*
** EPITECH PROJECT, 2018
** my_unsetenv.c
** File description:
** fct for unset a variable of environnement
*/

#include "my_shell.h"

void my_unsetenv(char *variable, mshell_l *sh)
{
    int nb = 0;
    char *temp;
    char *save;

    (variable == NULL) ? write(1, "unsetenv: Too few arguments.\n", 29) : 0;
    if (variable == NULL || line_env(sh->env, variable) == -1)
        return;
    for (; sh->env[nb]; nb++);
    save = sh->env[line_env(sh->env, variable)];
    for (int i = 0, j = line_env(sh->env, variable); i < nb - 1; i++)
        if (j == i) {
            temp = sh->env[i];
            sh->env[i] = sh->env[i + 1];
            sh->env[i + 1] = temp;
            j++;
        }
    sh->env[nb - 1] = NULL;
    free (save);
}
