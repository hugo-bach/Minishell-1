/*
** EPITECH PROJECT, 2018
** error_env.c
** File description:
** fct who treat error of my env
*/

#include "my_shell.h"

int check_erenv(char *variable)
{
    static int s = 0;
    char *disp = "setenv: Variable name must begin with a letter.\n";

    if (variable[0] != '_' && ((variable[0] < 65 || (variable [0] > 90 &&
        variable[0] < 97) || variable[0] > 122))) {
        if ((s % 2) == 0)
            write(1, disp, 48);
        s++;
        return (1);
    }
    for (int i = 1; variable[i]; i++)
        if (variable[i] < 48 || (variable[i] > 57 && variable[i] < 65) ||
        variable[i] > 122) {
            if ((s % 2) == 0)
                write(1, disp, 48);
            s++;
            return (1);
        }
    return (0);
}
