#include "shell.h"

void _cd(void)
{
	printf("cd typed\n");
}
void _env(void)
{
	printf("env typed\n");
}
void _exit(int status)
{
	printf("exit typed\n");
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
