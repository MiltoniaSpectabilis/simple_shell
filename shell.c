#include "shell.h"

/**
 * main - Main function
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Shell's exit status
 */
int main(int argc, char *argv[])
{

	ShellData shell;

	char *cmd = NULL;
	(void)argc;
	shell.program = argv[0];
	shell.line_num = 0;
	shell.status = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			print_prompt(&shell);
			cmd = read_cmd();
			if (cmd == NULL)
				break;
			exec_cmd(&shell, cmd);
		}
	}
	else
	{
		while ((cmd = read_cmd()) != NULL)
		{
			shell.line_num++;
			exec_cmd(&shell, cmd);
		}
	}

	return (shell.status);
}
