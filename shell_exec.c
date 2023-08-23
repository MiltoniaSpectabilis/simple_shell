#include "shell.h"

/**
 * exec_cmd_from_cp - Executes a command from the current path
 * @data: ShellData struct
 * @cmd: Command to execute
 * @args: Array of command arguments
 * @full_path: Full path of the command
 */
void exec_cmd_from_cp(ShellData *data, char *cmd, char **args, char *full_path)
{
	if (full_path != NULL && access(full_path, F_OK) == 0)
	{
		if (access(full_path, X_OK) == -1)
		{
			print_error(data, cmd);
			free_arr(args);
			free(cmd);
			if (full_path)
				free(full_path);
			exit(127);
		}
		if (execve(full_path, args, environ) != -1)
		{
			free_arr(args);
			if (full_path)
				free(full_path);
			exit(EXIT_SUCCESS);
		}
	}
	if (strchr(args[0], '/') == NULL)
	{
		print_error(data, cmd);
		free_arr(args);
		free(cmd);
		if (full_path)
			free(full_path);
		exit(127);
	}
	if (execve(args[0], args, environ) == -1)
	{
		print_error(data, cmd);
		free_arr(args);
		free(cmd);
		if (full_path)
			free(full_path);
		exit(127);
	}
}

/**
 * exec_cmd - Executes a command
 * @data: ShellData struct
 * @cmd: Command to execute
 */
void exec_cmd(ShellData *data, char *cmd)
{
	pid_t pid;
	char **args = NULL;
	char *full_path = NULL;

	if (cmd[0] == '\0')
	{
		free(cmd);
		return;
	}
	if (handle_exit(data, cmd) == 0)
		return;
	if (handle_env(cmd) == 0)
		/*free(cmd);*/
		return;
	pid = fork();
	if (pid == 0)
	{
		args = splitter(cmd);
		if (args == NULL || args[0] == NULL)
		{
			free_arr(args);
			free(cmd);
			return;
		}
		full_path = check_path(args[0]);
		exec_cmd_from_cp(data, cmd, args, full_path);
	}
	else
	{
		wait(&data->status);
		if (WIFEXITED(data->status))
			data->status = WEXITSTATUS(data->status);
		else
			data->status = 127;
	}
	free(cmd);
}
