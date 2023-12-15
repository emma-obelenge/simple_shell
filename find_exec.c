#include "shell.h"

/**
 * find_exec - searches for executable file path
 * @cmd: the user typed command
 * @found_path: pointer to the path when found
 *
 * Return: -1 on failure and 5 on success
 */
int find_exec(char **cmd, char **found_path)
{
	char *path_env, *path_token, *full_path;
	size_t full_path_len;

	if (cmd_is_path(cmd[0]) == 0)
	{
		*found_path = strdup(cmd[0]);
		return (5);
	}
	path_env = strdup(getenv("PATH"));
	if (path_env == NULL)
		return (-1);
	/* Tokenize the PATH environment variable*/
	path_token = strtok(path_env, ":");
	while (path_token != NULL)
	{
		full_path_len = strlen(path_token) + 1 + strlen(*cmd) + 1;
		full_path = (char *)malloc(full_path_len);
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, path_token);
		strcat(full_path, "/");
		strcat(full_path, *cmd);
		/* Check if the full path exists and is executable*/
		if (access(full_path, X_OK) == 0)
		{
			*found_path = full_path;
			free(path_env);
			return (5);
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	/* No executable found in any path*/
	free(path_env);
	free(path_token);
	return (-1);
}
