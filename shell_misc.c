#include "shell.h"

/**
 * handle_exit - Handles the 'exit' command
 * @data: ShellData struct
 * @cmd: Command to handle
 * Return: 1 if the command is not 'exit',
 *         2 if an error occurred, 0 otherwise
 */
int handle_exit(ShellData *data, char *cmd)
{
	if (_strcmp(cmd, "exit") == 0)
	{
		if (data->status != 0)
		{
			free(cmd);
			exit(2);
		}
		else
		{
			free(cmd);
			exit(0);
		}
	}
	return (1);
}

/**
 * read_cmd - Reads a command from stdin
 * Return: The command read
 */
char *read_cmd(void)
{
	char *cmd = NULL;
	size_t buff_size = 0;
	ssize_t line_len;

	line_len = getline(&cmd, &buff_size, stdin);
	if (line_len == -1)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
			_putchar('\n');
		return (NULL);
	}
	if (cmd[line_len - 1] == '\n')
		cmd[line_len - 1] = '\0';

	return (cmd);
}
