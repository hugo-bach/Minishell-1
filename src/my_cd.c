/*
** EPITECH PROJECT, 2018
** my_cd.c
** File description:
** fct cd
*/

#include "my_shell.h"


char *pars_line_env(char *str)
{
    char *result;
    int nb = 0;
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; str[i] != '='; i++, nb++);
    for (i = i + 1; str[i]; i++);
    i = i - nb;
    result = my_calloc(i);
    for (int i = nb + 1, j = 0; str[i]; i++, j++)
        result[j] = str[i];
    return (result);
}

void my_cd_old(mshell_l *sh, char *path)
{
    int fd = 0;
    char *pt = my_calloc(PATH_MAX);

    if (sh->arg[1][0] == '-' && sh->arg[1][1] == '\0') {
        fd = chdir(sh->oldpath);
        (fd == -1) ? error_erno("", errno) : 0;
        (fd != -1) ? my_setenv("PWD", sh->oldpath, sh), free(sh->oldpath), sh->oldpath = path : 0;
    } else if (sh->arg[1] != NULL && sh->arg[1][0] != '-') {
        fd = chdir(sh->arg[1]);
        (fd == -1) ? error_erno(sh->arg[1], errno) : 0;
        getcwd(pt, 100);
        (fd != -1) ? free (sh->oldpath), my_setenv("PWD", pt, sh),
        sh->oldpath = path : 0;
    } else
        write(1, "Usage: cd [-plvn][-|<dir>].\n", 28);
    free (pt);
}

void my_cd(mshell_l *sh)
{
    int fd = 0;
    char *st = pars_line_env(my_getenv(sh->env, "HOME"));
    char *pt = my_calloc(PATH_MAX);

    if (my_strlen_str(sh->arg) > 2) {
        write(1, "cd: Too many arguments.\n", 24);
        return;
    }
    getcwd(pt, 100);
    if (sh->arg[1] == NULL) {
        fd = chdir(st);
        (fd == -1 && st == NULL) ? write(1, "cd: No home directory.\n", 23) : 0;
        (fd == -1 && st != NULL) ?
        write(1, "cd: Can't change to home directory.\n", 36) : 0;
        (fd != -1) ? free (sh->oldpath), sh->oldpath = pt,
        my_setenv("PWD", st, sh) : 0;
    }
    if (sh->arg[1] != NULL)
        my_cd_old(sh, pt);
    (st != NULL) ? free (st) : 0;
}
