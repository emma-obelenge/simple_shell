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
int checker(strArr_int tokensNcount, int *builtin_value, char **found_path)
{
	int status;

	status = find_builtin(tokensNcount.tokens);
	if (status >= 0 && status < 5)
	{
		*builtin_value = status;
		return (status);
	}
	else
	{
		status = find_exec(tokensNcount.tokens[0], found_path);
		if (status == 0)
			return (6);
		else
			return (-1);
	}
}

/**
 * find_builtin - Would check if the user typed command is a builtin
 * @usr_cmd: The command typed by the user
 * @builtin_value: pointer to variable for holding builtin cases
 *
 * Return: 1, 2, 3, 4, or 5 if the user typed cd, env, exit, setenv,
 * or unsetenv respectively
 */
int find_builtin(char **usr_cmd)
{
	char *builtin[] = {"cd", "env", "exit", "setenv", "unsetenv", "NULL"};
	int i;

	i = 0;
	while (builtin[i] != NULL)
	{
		if (_strcmp(usr_cmd[0], builtin[i]) == 0)
		{
			/*
			   if (i == 2)
			{
				free(usr_cmd);
				free(untokenized_str_buf);
				builtin_exit();
			}
			*/
			return (i);
		}
		i++;
	}
	return (-1);
}

/**
 * find_exec - Would check if the user typed command is an executable
 * @cmd: The command typed by the user
 * @exec_path: Variable to contain the path where the executable was found
 * Return: Returns 0 on succes and -1 on failure
 */
int find_exec(char *cmd, char **found_path)
{
	char *paths = get_env("PATH");
	char *paths_token = strtok(paths, ":");
	char *found_path_dynamic;
	int paths_token_len, cmd_len, found_path_len;

	while (paths_token != NULL)
	{
		paths_token_len = _strlen(paths_token);
		cmd_len = _strlen(cmd);

		/*Allocate memory for the full path*/
		found_path_len = paths_token_len + cmd_len + 2;
		found_path_dynamic = malloc(found_path_len);
		if (found_path_dynamic == NULL)
		{
			free(found_path_dynamic);
			perror("malloc issue for found_path_local in find_exec func");
			return (-1);
		}

		/*Construct the full path*/
		_strcpy(found_path_dynamic, paths_token);
		_strapp(found_path_dynamic, "/", found_path_len);
		_strapp(found_path_dynamic, cmd, found_path_len);

		/*Check if the file exists and is executable*/
		if (access(found_path_dynamic, X_OK) == 0)
		{
			*found_path = found_path_dynamic;
			return (0);
		}
		/*
		 *Remember to Free the allocated memory for the exec_path
		 *free(exec_path);
		 */

		/*Move to the next directory in the PATH*/
		paths_token = strtok(NULL, ":");
	}
	/*If no executable is found*/
	free(found_path_dynamic);
	return (-1);
}
