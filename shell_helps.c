#include "shell.h"

/**
 * num2str - Converts a number to a string
 * @num: Number to convert
 * @str: Output string
 */
void num2str(int num, char *str)
{
	int i, j;
	char temp;

	i = 0;
	while (num != 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	str[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
}

/**
 * print_error - Prints an error message
 * @data: ShellData struct
 * @cmd: Command causing the error
 */
void print_error(ShellData *data, char *cmd)
{
	int line_num = data->line_num;
	char line_str[10];

	num2str(line_num, line_str);
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, cmd, strlen(cmd));
		write(STDOUT_FILENO, ": command not found\n", 20);
	}
	else
	{
		write(STDERR_FILENO, data->program, strlen(data->program));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line_str, strlen(line_str));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, strlen(cmd));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment variable
 * Return: Value of the environment variable, NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = _strlen(name);

	while (environ[i])
	{
		if (_strncmp(name, environ[i], len) == 0 &&
				environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}
