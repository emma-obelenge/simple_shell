#include "shell.h"
/**
 * builtin_exec - Toggles any of the builtin command and
 * places a call to execute them as required
 * @usr_cmd: array of strings of the user typed command
 * @_case: the case returned by the checker for executing builtin
 */
void builtin_exec(char **cmd_arr, int _case)
{
	if (_case >= 0 && _case < 5)
	{
		switch (_case)
		{
			case 0:
				/*cd call*/
				_cd();
				/*free_buf(cmd_arr, NULL, 0);*/
				break;
			case 1:
				/*env call*/
				_env();
				/*free_buf(cmd_arr, NULL, 0);*/
				break;
			case 2:
				/*exit call*/
				free_buf(cmd_arr, NULL, 0);
				_exit(EXIT_FAILURE);
				break;
			case 3:
				/*setenv call*/
				/*free_buf(cmd_arr, NULL, 0);*/
				_setenv();
				break;
			case 4:
				/*unsetenv call*/
				/*free_buf(cmd_arr, NULL, 0);*/
				_unsetenv();
				break;
			default:
				break;
		}
	}
}
