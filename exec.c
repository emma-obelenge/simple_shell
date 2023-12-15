#include "shell.h"

/**
 * exec - executes a command
 * @cmd_arr: array of strings containing user input cmd and args
 * @path: the found_path variable
 *
 */
void exec(char **cmd_arr, char *path)
{
	pid_t pid;
	int status;
	char **env;

	env = environ;
	pid = fork();
	if (pid == -1)
	{
		perror("fork process failed");
		free_buf(cmd_arr, NULL, 0);
		free_buf(NULL, path, 1);
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, cmd_arr, env) == -1)
		{
			perror("execve failed");
			free_buf(cmd_arr, NULL, 0);
			free_buf(NULL, path, 1);
			_exit(EXIT_FAILURE);
		}
	}
	if (pid > 0)
		wait(&status);
}
