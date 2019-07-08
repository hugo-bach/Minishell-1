/*
** EPITECH PROJECT, 2018
** treat_command.c
** File description:
** fct who treat input command
*/

#include "my_shell.h"

int treat_access(char **path, mshell_l *sh)
{
    int fd = 0;
    DIR *fl = NULL;
    char *temp = NULL;

    for (int i = 0; path[i]; i++) {
        fl = opendir(path[i]);
        temp = my_strcat_path(path[i], sh->arg[0]);
        fd = access(temp, F_OK);
        free (temp);
        if (fd != -1 && fl != NULL && sh->arg[0][0] != '\0') {
            exec_binary(sh->arg, sh->env, path[i]);
            (fl != NULL) ? free (fl) : 0;
            return (-1);
        }
        (fl != NULL) ? free (fl) : 0;
    }
    return (0);
}

int command_next(mshell_l *sh, int statut, char **path)
{
    int fd = 0;

    if (path != NULL)
        if (treat_access(path, sh) == -1)
            return (-1);
    fd = access(sh->arg[0], F_OK);
    if (fd != -1 && sh->arg[0][0] != '\n') {
        exec_binary(sh->arg, sh->env, NULL);
        statut++;
        return (-1);
    }
    return (statut);
}

void tt_command(mshell_l *sh, int statut)
{
    if (my_strcmp(sh->arg[0], "unsetenv") == 1) {
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
