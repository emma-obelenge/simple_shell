#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stddef.h>

extern char **environ;

int _strlen(const char *s);
char *prompt(void);
int input(char **usr_input);
char **parser(char *input);
char *_strcpy(char *src, char *dest);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
void _env(void);
void _cd(void);
void _exit(int status);
void _setenv(void);
void _unsetenv(void);
int _putchar(char c);
void _putsXnewline(char *str);
void builtin_exec(char **usr_cmd, int _case);
int checker(char **cmd_arr, int *builtin_value);
void _strapp(char *dest, char *src, int dest_len);
int find_exec(char **cmd, char **found_path);
int find_builtin(char **cmd_arr);
char *get_env(char *name);
int _strncmp(char *s1, char *s2, int n);
void for_builtin(char **cmd_arr);
void for_execve(char **cmd_arr, char *path);
int tok_count(char *input);
void free_buf(char **usr_cmd, char *path, int status);
void for_path(char *path);
void for_cmd_arr(char **cmd_arr);
int cmd_is_path(const char *cmd);
void exec(char **cmd_arr, char *path);
void found_path_dynamic(char *found_path);
void _printf(const char *format, ...);

#endif
