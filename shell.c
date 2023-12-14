#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{
	char **cmd_arr = NULL;
	char *usr_input = NULL, *found_path = NULL; 
	while (true)
	{
		int checker_report = -1, builtin_value = -1;
		int *value = &builtin_value, i = 0;

		usr_input = prompt();
		if (usr_input == NULL)
			continue;
		cmd_arr = parser(usr_input);
		for (; cmd_arr[i]; i++)
			printf("cmd_arr[%d] is: %s", i, cmd_arr[i]);
		checker_report = checker(cmd_arr, value);
		if (checker_report == 0)
		{
			builtin_exec(cmd_arr, builtin_value);
		}
		else
		{
			builtin_value = find_exec(cmd_arr, &found_path);
		}
			/*cmd_exe*/
		if (builtin_value == 5)
		{
			exec(cmd_arr, found_path);
			continue;
		}
		_printf("%s: %d: not found\n", cmd_arr[0], 1);
		free_buf(cmd_arr, NULL, 0);
		free_buf(NULL, found_path, 1);
	}
	return (0);
}
