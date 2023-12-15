#include "shell.h"

void _cd(void)
{
	printf("cd typed\n");
}
void _env(char **str)
{
	if (str[1])
	{
		printf("env: '%s': No such file or directory\n", str[1]);
	}
	else
	{
		char **env_var = environ;
		while (*env_var)
		{
			printf("%s\n", *env_var);
			env_var++;
		}
	}
}
void _exit(int status)
{
	exit(status);
}
void _setenv(void)
{
	printf("setenv typed\n");
}
void _unsetenv(void)
{
	printf("unsetenv typed\n");
}
