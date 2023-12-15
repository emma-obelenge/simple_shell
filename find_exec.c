#include "shell.h"

int find_exec(char **cmd, char **found_path)
{
	char *path_env, *path_token, *full_path;
	size_t full_path_len;

	/* Get the value of the PATH environment variable*/
	path_env = strdup(getenv("PATH"));
	/* If PATH is not set, return -1*/
	if (path_env == NULL)
	{
		return -1;
	}
	/* Tokenize the PATH environment variable*/
	path_token = strtok(path_env, ":");
	/* Loop through each tokenized path*/
	while (path_token != NULL)
	{
		/*Allocate memory for the full path (path + "/" + cmd)*/
		full_path_len = strlen(path_token) + 1 + strlen(*cmd) + 1;
		full_path = (char *)malloc(full_path_len);
		/*Check if memory allocation is successful*/
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		/* Construct the full path*/
		strcpy(full_path, path_token);
		strcat(full_path, "/");
		strcat(full_path, *cmd);
		/* Check if the full path exists and is executable*/
		if (access(full_path, X_OK) == 0)
		{
			*found_path = full_path;
			free(path_env);
			return 5;
		}
		/*Free the memory for full path and path_token*/
		free(full_path);
		/* Move to the next tokenized path*/
		path_token = strtok(NULL, ":");
	}
	/* No executable found in any path*/
	free(path_env);
	free(path_token);
	return -1;
}
