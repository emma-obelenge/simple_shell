#include "shell.h"

/**
 * checker - tells if the user input is a builtin or executable
 * @tokensNcount: strArr_int type data of user input str and count
 * @builtin_value: pointer to integer for holding builtin_exec cases
 * @exec_path: str pointer for holding the path to the executable found
 *
 * Return: Returns 1 if user command is a builtin, 2 if user
 * is an executable, and -1 when non of these are true
 */
int checker(char **cmd_arr, int *builtin_value)
{
	int status;

	status = find_builtin(cmd_arr);
	if (status >= 0 && status < 5)
	{
		*builtin_value = status;
		return (0);
	}
	return (-1);
}

/**
 * find_builtin - Would check if the user typed command is a builtin
 * @usr_cmd: The command typed by the user
 * @builtin_value: pointer to variable for holding builtin cases
 *
 * Return: 1, 2, 3, 4, or 5 if the user typed cd, env, exit, setenv,
 * or unsetenv respectively
 */
int find_builtin(char **cmd_arr)
{
	char *builtin[] = {"cd", "env", "exit", "setenv", "unsetenv", "NULL"};
	int i = 0;
	if (cmd_arr == NULL || cmd_arr[0] == NULL)
	{
		return (-1);
	}
	while (builtin[i])
	{
		if (_strcmp(cmd_arr[0], builtin[i]) == 0)
		{
			return (i);
		}
		i++;
		/* wahala zone. dont touch this if statement oo*/
		if (i == 5)
		{
			return (-1);
		}
	}
	return(-1);
}
