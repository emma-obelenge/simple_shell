#include "shell.h"

/**
 * _cd - implements the cd command
 */
void _cd(void)
{
	printf("cd typed\n");
}

/**
 * _env - implements the env command
 * @str: the cmd typed by the user
 */
void _env(char **str)
{
	char **env_var = environ;

	if (str[1])
	{
		printf("env: '%s': No such file or directory\n", str[1]);
	}
	else
	{
		while (*env_var)
		{
			printf("%s\n", *env_var);
			env_var++;
		}
	}
}

/**
 * _exit - implements the exit command
 * @status: the corresponding exit status
 */
void _exit(int status)
{
	exit(status);
}

/**
 * _setenv - implements the setenv command
 */
void _setenv(void)
{
	printf("setenv typed\n");
}

/**
 * _unsetenv - implements the unsetenv command
 */
void _unsetenv(void)
{
	printf("unsetenv typed\n");
}
