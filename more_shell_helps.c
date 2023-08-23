#include "shell.h"

/**
 * check_path - Checks the PATH for the existence of a command
 * @cmd: Command to check
 * Return: Full path of the command, NULL if not found
 */
char *check_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *path_cpy = NULL, *dir = NULL, *full_path = NULL;

	if (path == NULL || cmd == NULL)
		return (NULL);

	path_cpy = _strdup(path);
	dir = strtok(path_cpy, ":");

	while (dir)
	{
		full_path = malloc(_strlen(dir) + _strlen(cmd) + 2);

		if (full_path == NULL)
		{
			free(path_cpy);
			return (NULL);
		}

		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_cpy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_cpy);
	return (NULL);
}

/**
 * splitter - Splits a string into an array of tokens
 * @input: Input string to split
 * Return: Array of tokens
 */
char **splitter(const char *input)
{
	char *str;
	int count = 0;
	char **result;
	char *tok;

	str = _strdup(input);
	result = malloc(MAX_TOKENS_NUM * sizeof(*result));

	tok = strtok(str, " \n\t");

	while (tok != NULL && count < MAX_TOKENS_NUM - 1)
	{
		if (_strlen(tok) > 0)
		{
			result[count] = _strdup(tok);
			count++;
		}
		tok = strtok(NULL, " \n\t");
	}
	result[count] = NULL;
	free(str);

	return (result);
}

/**
 * free_arr - Frees an array of strings
 * @str: Array of strings
 */
void free_arr(char **str)
{
	int i;

	for (i = 0; str[i]; ++i)
		free(str[i]);
	free(str);
}
