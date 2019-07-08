/*
** EPITECH PROJECT, 2018
** my_prompt.c
** File description:
** fct who display and read the command line
*/

#include "my_shell.h"

void my_free(char **str)
{
    if (str == NULL)
        return;
    if (str[0] == NULL)
        return;
    for (int i = 0; str[i]; i++)
        free (str[i]);
    free (str);
}

char *delete_char(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    return (str);
}

char *my_str(char *str1, char *str2)
{
    int nb = 0;
    char *result = NULL;

    for (; str1[nb]; nb++);
    if (str2 != NULL)
        for (int i = 0; str2[i]; i++, nb++);
    result = my_calloc(nb);
    for (nb = 0; str1[nb]; nb++)
        result[nb] = str1[nb];
    if (str2 == NULL)
        return (result);
    if (str1 != NULL)
        free (str1);
    for (int i = 0; str2[i]; i++, nb++)
        result[nb] = str2[i];
    return (result);
}

void parsing_command(mshell_l *sh, char *result)
{
    int nb = 0;
    int k = 0;

    if (sh->arg != NULL)
        my_free(sh->arg);
    for (; result[nb] == ' '; nb++);
    for (int i = nb; result[i + 1] != '\n'; i++)
        if (result[i] == ' ' && result[i + 1] != ' ')
            (nb == 0) ? nb = 2 : nb++;
    (nb == 0) ? nb = 1 : 0;
    sh->arg = my_strcalloc(nb);
    for (nb = 0; result[nb] == ' '; nb++);
    for (int i = nb; result[i] != ' ' && result[i] != '\n'; k++, i++);
    sh->arg[0] = my_calloc(k);
    for (nb = 0; result[nb] == ' '; nb++);
    for (int i = nb, nb = 0, j = 0, x = 0; result[i] != '\n'; i++) {
        if (result[i] == ' ' && result[i + 1] != ' ' && result[i + 1] != '\n') {
            for (; result[i] == ' ' && result[i] != '\n'; i++);
            j = 0;
            for (int p = i; result[p] != ' ' && result[p] != '\n'; j++, p++);
            nb++;
            sh->arg[nb] = my_calloc(j);
            x = 0;
            i--;
        } else if (result[i] != ' ' && result[i] != '\n' && result[i]) {
            sh->arg[nb][x] = result[i];
            x++;
        }
    }
    free (result);
}

void my_prompt(mshell_l *sh)
{
    char *result = NULL;
    int rd = 0;
    size_t len = 0;
    char *pwd = my_getenv(sh->env, "PWD") + 4;
    char *home = my_getenv(sh->env, "HOME");
    char *prompt = NULL;

    if (isatty(0) && home != NULL && my_strcmp_home(pwd, home + 5) == 1) {
        prompt = my_str("\033[1;93m~\033[1;31m", prompt);
        prompt = my_str(prompt, pwd + my_strlen(home + 5));
    }
    if (prompt == NULL) {
        prompt = my_str("\033[1;31m", prompt);
        prompt = my_str(prompt, pwd);
    }
    prompt = my_str(prompt, "\033[0m\033[1;93m~> \033[0m");
    write(1, prompt, my_strlen(prompt));
    free (prompt);
    (result != NULL) ? free(result), free(pwd) : 0;
    write(1, "\033[1;34m", 7);
    rd = getline(&result, &len, stdin);
    write(1, "\033[0m", 4);
    (rd == -1) ? write(1, "\033[1;32mexit", 11), free (result), my_exit (sh): 0;
    delete_char(result);
    write(sh->fd, result, my_strlen(result));
    parsing_command(sh, result);
}
