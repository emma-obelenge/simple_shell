#include "shell.h"

/**
 * cmd_exec - executes a command
 * @input: array of strings containing user input cmd and args
 *
 * Return: 0 on success, otherwise -1.
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
