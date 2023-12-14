#include "shell.h"

void free_buf(char **cmd_arr, char *path, int status)
{
	if (status >= 0 && status <= 2)
	{
		switch (status)
		{
			case 0:
				for_cmd_arr(cmd_arr);
				break;
			case 1:
				for_path(path);
				break;
			case 2:
				found_path_dynamic(path);
				break;
			default:
				break;
		}
	}
}

void for_path(char *path)
{
	if(path != NULL)
	{
		free(path);
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
	}
}
void found_path_dynamic(char *found_path)
{
	if (found_path != NULL)
	{
		free(found_path);
	}
}
