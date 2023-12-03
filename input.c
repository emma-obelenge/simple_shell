#include "shell.h"

/**
  * input - get user input from stdin
  *
  * Return: the user input
  */
char *input(void)
{
	size_t n = 0;
	char *buf = NULL;
	ssize_t len;

	len = getline(&buf, &n, stdin);
	if (len == -1)
	{
		free(buf);
		return (NULL);
	}

	buf[len - 1] = '\0';

	return (buf);
}
