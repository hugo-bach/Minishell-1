/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** function main of my minishell1
*/

#include "my_shell.h"

char *my_strcopy(char *str)
{
    char *result = my_calloc(my_strlen(str));

    for (int i = 0; str[i]; i++)
        result[i] = str[i];
    return (result);
}

mshell_l set_shell(char **env, mshell_l sh)
{
    int nb = 0;

    for (; env[nb] != NULL; nb++);
    sh.env = my_strcalloc(nb);
    for (int i = 0; env[i]; i++)
        sh.env[i] = my_strcopy(env[i]);
    sh.arg = NULL;
    sh.oldpath = my_calloc(PATH_MAX);
    return (sh);
}

int main(int ac, __attribute__((unused)) char **av, char **env)
{
    mshell_l sh = set_shell(env, sh);

    if (ac != 1)
        return (84);
    sh.fd = open(".myshrc", O_CREAT | O_RDWR, 0666);
    my_shell(&sh);
}
