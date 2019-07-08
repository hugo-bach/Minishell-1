/*
** EPITECH PROJECT, 2018
** treat_command2.c
** File description:
** fct who treat all command of my minishell
*/

#include "my_shell.h"

char *my_strcat_path(char *first, char *second)
{
    int nb = 0;
    char *result;

    if (first != NULL)
        for (; first[nb]; nb++);
    if (second != NULL)
        for (int i = 0; second[i]; i++, nb++);
    result = my_calloc(nb + 1);
    if (first != NULL)
        for (nb = 0; first[nb]; nb++)
            result[nb] = first[nb];
    (result[nb] != '/' && first != NULL) ? result[nb++] = '/' : 0;
    (first == NULL) ? nb = 0 : 0;
    if (second != NULL)
        for (int i = 0; second[i]; i++, nb++)
            result[nb] = second[i];
    return (result);
}

void verif_status(int status, char *str)
{
    my_macro(status%255);
    if (WIFSIGNALED(status) > 0) {
        if (WTERMSIG(status) == 11)
            write(1, "Segmentation fault", 18);
        if (WTERMSIG(status) == 8)
            write(1, "Floating exception", 18);
        if (WCOREDUMP(status))
            write(1, " (core dumped)", 14);
        write(1, "\n", 1);
    }
    if (status == -1) {
        write(1, str, my_strlen(str));
        write(1, ": Exec format error. Wrong Architecture.\n", 41);
    }
}

void exec_binary(char **command, char **env, char *test)
{
    pid_t pid = fork();
    int fd = 0;
    int status = 0;

    if (pid == -1) {
        perror("");
        return;
    } else if (pid == 0) {
        fd = execve(my_strcat_path(test, command[0]), command, env);
        (errno == 8) ? verif_status(-1, command[0]), exit (1) : 0;
        (fd == -1) ? error_erno(command[0], errno), exit (1) : 0;
    } else {
        waitpid(pid, &status, 0);
        verif_status(status, command[0]);
    }
}

void treat_command_next(mshell_l *sh, int statut)
{
    int fd = 0;
    char **path = NULL;

    if (my_getenv(sh->env, "PATH") != NULL)
        path = parsing_path(my_getenv(sh->env, "PATH"));
    if (sh->arg[0][0] == '.' && sh->arg[0][1] == '/') {
        fd = access(sh->arg[0], F_OK);
        (fd != -1) ? exec_binary(sh->arg, sh->env, NULL) : 0;
        (fd == -1) ? perror("") : 0;
        statut++;
        my_free(path);
    } else if (statut == 0) {
        statut = command_next(sh, statut, path);
        if (statut == -1) {
            my_free(path);
            return;
        }
    }
    my_free(path);
    (my_strcmp(sh->arg[0], "exit") == 1) ? my_exit(sh),
    statut++ : 0;
    (my_strcmp(sh->arg[0], "$status") == 1) ? printf("%d\n", my_macro(0)), statut++ : 0;
    (my_strcmp(sh->arg[0], "history") == 1) ? read_files(sh), statut++ : 0;
    if (statut == 0 && sh->arg[0][0] != '\0')
        (1) ? write(1, sh->arg[0], my_strlen(sh->arg[0])),
        write(1, ": Command not found.\n", 21): 0;
}
