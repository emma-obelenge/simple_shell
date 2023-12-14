#include "shell.h"

/**
 * find_exec - Would check if the user typed command is an executable
 * @cmd: The command typed by the user
 * @exec_path: Variable to contain the path where the executable was found
 * Return: Returns 0 on succes and -1 on failure
 */

int find_exec(char **cmd, char **found_path)
{
	char *paths = get_env("PATH");
	char *paths_token = strtok(paths, ":");
	char *found_path_dynamic;
	int paths_token_len, cmd_len, found_path_len;

	printf("entered find_exec\n");
	if (cmd_is_path(cmd[0]) == 0)
	{
		*found_path = _strdup(cmd[0]);
		printf("path changed to usr def path\n");
		return (5);
	}
	else if (!(cmd[0] == NULL))
	{
		while (paths_token != NULL)
		{
			printf("want to find path now\n");
			paths_token_len = _strlen(paths_token);
			cmd_len = _strlen(cmd[0]);
			/*Allocate memory for the full path*/
			found_path_len = paths_token_len + cmd_len + 2;
			found_path_dynamic = malloc(found_path_len);
			if (found_path_dynamic == NULL)
			{
				perror("malloc issue for found_path_dynamic in find_exec func");
				return (-1);
			}
			/*Construct the full path*/
			_strcpy(found_path_dynamic, paths_token);
			_strapp(found_path_dynamic, "/", found_path_len);
			_strapp(found_path_dynamic, cmd[0], found_path_len);
			printf("the merged part is: %s\n", found_path_dynamic);
			/*Check if the file exists and is executable*/
			if (access(found_path_dynamic, X_OK) == 0)
			{
				*found_path = found_path_dynamic;
				printf("path was found\n");
				return (5);
			}
			/*Move to the next directory in the PATH*/
			paths_token = strtok(NULL, ":");
		}
		/*If no executable is found*/
		free_buf(NULL, found_path_dynamic, 2);
		printf("path not found\n");
	}
	return (-1);
}
