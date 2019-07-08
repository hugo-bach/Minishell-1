/*
** EPITECH PROJECT, 2018
** read_files.c
** File description:
** 
*/

#include "my_shell.h"

void read_files(mshell_l *sh)
{
    char *arg[3];

    arg[0] = "cat";
    arg[1] = ".myshrc";
    arg[2] = NULL;
    exec_binary(arg, sh->env, "/bin");
    //execve("/bin/cat", arg, sh->env);
}
