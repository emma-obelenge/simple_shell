#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{
	char **cmd_arr;
	char *usr_input = NULL, *found_path = NULL; 
	while (true)
	{
		int checker_report = -1, builtin_value = -1;
		int *value = &builtin_value;
		usr_input = prompt();
		if (usr_input == NULL)
			continue;
		cmd_arr = parser(usr_input);
		checker_report = checker(cmd_arr, value);
		if (checker_report == 0)
		{
			builtin_exec(cmd_arr, builtin_value);
		}
		else
		{
			printf("just before execve");
			builtin_value = find_exec(cmd_arr[0], &found_path);
			/*cmd_exe*/
			printf("execve will be called here");
			/*call_free(status1, cmd_arr, found_path);*/
			free_buf(cmd_arr, found_path, 1);
		}
		if (builtin_value == -1)
		{
			_putsXnewline("cmd_arr[0]");
			_putsXnewline(": command not found\n");
			free_buf(cmd_arr, found_path, 1);
		}
	}
	return (0);
}
