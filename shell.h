#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS_NUM 100

extern char **environ;

/**
 * struct ShellData - Holds information about a shell program.
 * @program: Name of the program.
 * @line_num: Line number.
 * @status: Status of the program.
 */
typedef struct ShellData
{
	char *program;
	int line_num;
	int status;
} ShellData;

void print_prompt(ShellData *data);
int handle_env(char *cmd);
void num2str(int num, char *str);
void print_error(ShellData *data, char *cmd);
char *_getenv(const char *name);
char *check_path(char *cmd);
char **splitter(const char *input);
void free_arr(char **str);
int handle_exit(ShellData *data, char *cmd);
char *read_cmd(void);
void exec_cmd_from_cp(ShellData *data, char *cmd, char **args,
		char *full_path);
void exec_cmd(ShellData *data, char *cmd);

int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char *_strchr(const char *str, int c);
void _putchar(int c);
void _puts(const char *s);

#endif /* SHELL_H */
