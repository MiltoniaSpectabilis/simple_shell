#include "shell.h"

/**
 * _putchar - Custom implementation of putchar function
 * @c: The character to be printed
 *
 * Return: On success, returns the character written as an unsigned char
 *         cast to an int. On failure, returns EOF (-1) and sets errno.
 */
void _putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * _puts - Custom implementation of puts function
 * @s: The string to be printed
 */
void _puts(const char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}

/**
 * _strlen - Custom implementation of strlen function
 * @str: The string to calculate the length of
 *
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcmp - Custom implementation of strcmp function
 * @str1: The first string to compare
 * @str2: The second string to compare
 *
 * Return: Negative value if str1 < str2, 0 if str1 == str2,
 *         Positive value if str1 > str2
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] && str1[i] == str2[i])
		i++;

	return (str1[i] - str2[i]);
}

/**
 * _strncmp - Custom implementation of strncmp function
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: Negative value if str1 < str2, 0 if str1 == str2,
 *         Positive value if str1 > str2
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	while (i < n && str1[i] && str1[i] == str2[i])
		i++;

	if (i == n)
		return (0);

	return (str1[i] - str2[i]);
}
