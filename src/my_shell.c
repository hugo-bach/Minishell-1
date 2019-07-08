/*
** EPITECH PROJECT, 2018
** my_shell.c
** File description:
** this is my kernel of my shell
*/

#include "my_shell.h"

char *convert(int score)
{
    char *result;
    int count = 1;
    int i = 0;
    int pow = 1;

    for (int nb = score; nb > 9; count++) {
        pow = pow * 10;
        nb = nb / 10;
    }
    result = my_calloc(count);
    for (int nb = score; i < count; i++) {
        result[i] = (nb / pow) + 48;
        nb = nb % pow;
        pow = pow / 10;
    }
    return (result);
}

int take_nb(char *str)
{
    char *result;
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] >= 48 && str[i] <= 57)
            nb++;
    result = my_calloc(nb);
    for (int i = 0, nb = 0; str[i]; i++)
        if (str[i] >= 48 && str[i] <= 57)
            result[nb++] = str[i];
    nb = my_getnbr(result);
    free (result);
    return (nb);
}

void sh_lvl(mshell_l *sh)
{
    char *str = my_getenv(sh->env, "SHLVL");
    char *result;
    int nb = 0;

    if (str == NULL)
        my_setenv("SHLVL", "1", sh);
    else {
        nb = take_nb(str);
        result = convert(nb);
        nb++;
        my_setenv("SHLVL", result, sh);
        free (result);
    }
}

void treat_command(mshell_l *sh)
{
    int statut = 0;

    if (my_strcmp(sh->arg[0], "setenv") == 1) {
        if (my_strlen_str(sh->arg) > 3) {
            write(1, "setenv: Too many arguments.\n", 28);
            return;
        } else if (my_strlen_str(sh->arg) == 1)
            my_setenv(sh->arg[1], NULL, sh);
        (sh->arg[1] != NULL) ? my_setenv(sh->arg[1], sh->arg[2], sh) : 0;
        statut++;
    } else if (my_strcmp(sh->arg[0], "unsetenv") == 1) {
        if (my_strlen_str(sh->arg) == 1)
            write(1, "unsetenv: Too few arguments.\n", 29);
        else
            for (int i = 1; sh->arg[i]; i++)
                my_unsetenv(sh->arg[i], sh);
        statut++;
    }
    if (my_strcmp(sh->arg[0], "env") == 1)
        (1) ? my_env(sh->env), statut++ : 0;
    if (my_strcmp(sh->arg[0], "cd") == 1)
        (1) ? my_cd(sh), statut++ : 0;
    treat_command_next(sh, statut);
}

void my_shell(mshell_l *sh)
{
    char *path = my_calloc(PATH_MAX);

    sh_lvl(sh);
    my_setenv("PWD", getcwd(path, 100), sh);
    free (path);
    while (1) {
        my_prompt(sh);
        treat_command(sh);
    }
}
