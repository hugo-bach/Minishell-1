/*
** EPITECH PROJECT, 2018
** my_shell.h
** File description:
** header for my project minishell
*/

#ifndef MY_SHELL
#define MY_SHELL

#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

typedef struct minishell
{
    char **env;
    char **arg;
    char *oldpath;
    int fd;
} mshell_l;

void my_prompt(mshell_l *);
void parsing_command(mshell_l *, char *);
char *my_getenv(char **, char *);
int my_strcmp(char *, char *);
int my_strcmp_env(char *, char *);
char *my_calloc(int);
char **my_strcalloc(int);
char **parsing_path(char *);
void my_shell(mshell_l *);
int my_strlen(char *);
void my_env(char **);
void my_setenv(char *, char *, mshell_l *);
int line_env(char **, char *);
void my_unsetenv(char *, mshell_l *);
void treat_command(mshell_l *);
int my_strlen_str(char **);
int my_getnbr(char *);
void my_cd(mshell_l *);
char *pars_env(char *);
void my_exit(mshell_l *);
void error_erno(char *, int);
void treat_command_next(mshell_l *, int);
void my_free(char **);
int check_erenv(char *);
char *my_strcat_path(char *, char *);
void exec_binary(char **, char **, char *);
int command_next(mshell_l *, int, char **);
int my_strcmp_home(char *, char *);
char *my_strcat(char *, char *);
int my_macro(int);
void read_files(mshell_l *);
char *my_copy(char *, char *);
int line_env(char **, char *);

#endif //MY_SHELL
