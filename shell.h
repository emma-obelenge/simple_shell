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

int _strlen(char *s);
char *prompt(void);
char *input(void);
struct strArr_int parser(char *input);
char *_strcpy(char *src, char *dest);
char *_strdup(char *str);

struct strArr_int
{
	char **tokens;
	int tok_count;
};

#endif
