#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
