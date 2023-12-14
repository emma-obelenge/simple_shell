#include "shell.h"

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

	printf("entered find exec");
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
		 *Remember to Free the allocated memory for the found_path
		 *free(found_path);
		 */

		/*Move to the next directory in the PATH*/
		paths_token = strtok(NULL, ":");
	}
	/*If no executable is found*/
	free(found_path_dynamic);
	found_path_dynamic = NULL;
	return (-1);
}
