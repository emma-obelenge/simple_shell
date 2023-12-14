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
	int builtin_value = -1, checker_report;

	while (true)
	{
		usr_input = prompt();
		printf("usr_input is: %s", usr_input);
		/*
		   cmd_arr = parser(usr_input);
		if (cmd_arr == NULL)
			continue;
			*/
		/****
		i = 0;
		   while (*(usr_input + 1))
		{
		{
			printf("input %d is: %s\n", i, cmd_arr[i]);
			i++;
		}
		*****/
		/*
		checker_report = checker(cmd_arr, &builtin_value, &found_path);
		if (checker_report >= 0 && checker_report < 5)
		{
			builtin_exec(cmd_arr, builtin_value);
			call_free(0, cmd_arr, found_path);
		}
		else if(checker_report == 6)
		{
			/cmd_exe/
			printf("execve will be called here");
			/call_free(status1, cmd_arr, found_path);/
		}
		else
		{
			_putsXnewline("cmd_arr[0]");
			_putsXnewline(": command not found\n");
			call_free(0, cmd_arr, found_path);
		}
		*/
	}
	return (0);
}
