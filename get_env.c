#include "shell.h"

/**
 * get_env - extracts the required value from the environment variable
 * @name: The name of the variable taken as parameter
 *
 * Return: pointer to string value in the PATH variable
 * NULL with respect to conditions
 */
char *get_env(char *name)
{
	int i, temp;
	char **argv;
	char *var_line;

	argv = environ;
	for (i = 0; argv[i]; i++)
	{
		var_line = argv[i];
		/*check if the argument is of the form "NAME=VALUE"*/
		temp = _strncmp(var_line, name, _strlen(name));
		if (temp == 0 && var_line[_strlen(name)] == '=')
			return (var_line + _strlen(name) + 1);
	}
	return (NULL);
}
