#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int _strlen(char *s);
void prompt(void);
char *input(void);

#endif
