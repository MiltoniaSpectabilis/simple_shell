#include "shell.h"

/**
 * print_prompt - Prints the prompt string
 * @data: ShellData struct
 */
void print_prompt(ShellData *data)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "($) ", 4);
		data->line_num++;
	}
}

/**
 * handle_env - Handles the 'env' command
 * @cmd: Command to handle
 * Return: 0 if the command is 'env', 1 otherwise
 */
int handle_env(char *cmd)
{
	int i = 0;

	if (_strcmp(cmd, "env") == 0)
	{
		while (environ[i])
			_puts(environ[i++]);
		free(cmd);
		return (0);
	}
	return (1);
}
