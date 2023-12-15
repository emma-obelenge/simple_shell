#include "shell.h"

/**
 * free_buf - would free the allocated memory blocks
 * cmd_arr: the user typed string buff
 * path: the found path buff
 * status: value that triggers the respective freeing condition
 */
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

/**
 * for_path - frees the found_path buff
 */
void for_path(char *path)
{
	if (path != NULL)
	{
		free(path);
	}
}

/**
 * for_cmd_arr - frees the cmd_arr buff
 */
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

/**
 * found_p - frees the found_path buff
 */

/*
   void found_path_dynamic(char *found_path)
{
	if (found_path != NULL)
	{
		free(found_path);
	}
}
*/
