/*
** EPITECH PROJECT, 2018
** my_getenv.c
** File description:
** fct who treat the env
*/

#include "my_shell.h"

int my_strcmp_home(char *str, char *element)
{
    int nb = 0;

    if (element == NULL || str == NULL)
        return (-1);
    for (int i = 0; element[i] && str[i]; i++, nb++)
        if (element[i] != str[i])
            return (-1);
    if (nb != my_strlen(element))
        return (-1);
    return (1);
}

int my_strcmp(char *str, char *element)
{
    int nb = 0;

    if (element == NULL || str == NULL)
        return (-1);
    for (int i = 0; element[i] != '\0'; i++, nb++)
        if (element[i] != str[i])
            return (-1);
    if (nb != my_strlen(str))
        return (-1);
    return (1);
}

int my_strcmp_env(char *str, char *element)
{
    int nb = 0;

    for (int i = 0; element[i] != '\0'; i++, nb++)
        if (element[i] != str[i])
            return (-1);
    return (1);
}

char *my_getenv(char **env, char *element)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strcmp_env(env[i], element) == 1)
            return (env[i]);
    return (NULL);
}
