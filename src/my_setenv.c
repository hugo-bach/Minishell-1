/*
** EPITECH PROJECT, 2018
** my_setenv.c
** File description:
** fct who set the environement or display
*/

#include "my_shell.h"

char *pars_env(char *str)
{
    char *result = my_calloc(my_strlen(str));

    for (int i = 0; str[i] != '='; i++)
        result[i] = str[i];
    return (result);
}

char *my_strcat(char *first, char *second)
{
    int nb = 0;
    char *result;

    for (; first[nb]; nb++);
    if (second != NULL)
        for (int i = 0; second[i]; i++, nb++);
    result = my_calloc(nb + 1);
    for (nb = 0; first[nb]; nb++)
        result[nb] = first[nb];
    result[nb++] = '=';
    if (second != NULL)
        for (int i = 0; second[i]; i++, nb++)
            result[nb] = second[i];
    return (result);
}

char *my_copy(char *first, char *second)
{
    int nb = 0;

    for (; first[nb]; nb++);
    second = my_calloc(nb);
    for (int i = 0; first[i]; i++)
        second[i] = first[i];
    free (first);
    return (second);
}

int line_env(char **env, char *variable)
{
    int line = 0;
    char *result;

    for (; env[line]; line++) {
        result = pars_env(env[line]);
        if (my_strcmp(result, variable) == 1) {
            free (result);
            return (line);
        }
        free (result);
    }
    return (-1);
}

void my_setenv(char *variable, char *value, mshell_l *sh)
{
    char **temp = NULL;
    char *test = NULL;
    int nb = 1;

    (variable == NULL) ? my_env(sh->env) : 0;
    if (variable == NULL)
        return;
    if (line_env(sh->env, variable) == -1 && check_erenv(variable) == 0) {
        for (int i = 0; sh->env[i]; nb++, i++);
        temp = my_strcalloc(nb);
        for (nb = 0; sh->env[nb]; nb++)
            temp[nb] = my_copy(sh->env[nb], temp[nb]);
        temp[nb] = my_strcat(variable, value);
        (1) ? free (sh->env), sh->env = temp : 0;
    } else if (check_erenv(variable) == 0) {
        test = sh->env[line_env(sh->env, variable)];
        sh->env[line_env(sh->env, variable)] = my_strcat(variable, value);
        free (test);
    }
}
