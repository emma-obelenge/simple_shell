#include "shell.h"

void free_buf(char **cmd_arr, char *path, int status)
{
	if (status == 0)
		for_cmd_arr(cmd_arr);
	else if (status == 1)
	{
		for_cmd_arr(cmd_arr);
		for_path(path);
	}
}

void for_path(char *path)
{
	if(path != NULL)
	{
		free(path);
		path = NULL;
	}
}

void for_cmd_arr(char **cmd_arr)
{
	if (cmd_arr != NULL)
	{
		int i = 0;

		while (cmd_arr[i] != NULL)
		{
			free(cmd_arr[i]);
			i++;
		}
		free(cmd_arr);
		cmd_arr = NULL;
	}
}
