#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct strArr_int - Would hold the tokenized array of strings
 * and keep track of the number of string entered
 * @tokens: Array of tokenized strings
 * @tok_count: number of command entered
 */
struct strArr_int
{
	char **tokens;
	int tok_count;
};

extern char **environ;
typedef struct strArr_int strArr_int;

int _strlen(char *s);
char *prompt(void);
char *input(void);
struct strArr_int parser(char *input);
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
void builtin_exec(char **usr_cmd, int _case, char *untokenized_str_buf);
int checker(strArr_int tokensNcount, int *builtin_value, char **found_path);
void _strapp(char *dest, char *src, int dest_len);
int find_exec(char *cmd, char **found_path);
int find_builtin(char **usr_cmd);
char *get_env(char *name);
int _strncmp(char *s1, char *s2, int n);

#endif
