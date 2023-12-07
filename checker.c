#include "shell.h"
/**
 * checker - Compares the tokenized input with a list of builtin
 * when it finds a match, it calls on the corresponding builtin
 * @usr_cmd: The array of tokenized strings the user typed
 *
 * Return: Returns 0 on success, and 1 on the reverse scenario
 */
int checker(char **usr_cmd,)
{
	char **builtin = {"env", "exit", "setenv", "unsetenv", "cd", NULL};
	int i;

	while (builtin[i] != NULL)
	{
		if (_strcmp(usr_cmd.[0], builtin[i]
