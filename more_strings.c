#include "shell.h"

/**
 * _strcpy - Custom implementation of strcpy function
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: Pointer to destination string
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Custom implementation of strcat function
 * @dest: The destination string
 * @src: The source string to be concatenated
 *
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	int destLen = _strlen(dest), i = 0;

	while (src[i] != '\0')
	{
		dest[destLen + i] = src[i];
		i++;
	}
	dest[destLen + i] = '\0';

	return (dest);
}

/**
 * _strdup - Custom implementation of strdup function
 * @str: The string to be duplicated
 *
 * Return: Pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	char *dup = malloc((_strlen(str) + 1) * sizeof(char));

	if (dup != NULL)
		_strcpy(dup, str);

	return (dup);
}

/**
 * _strchr - Custom implementation of strchr function
 * @str: The string to be searched
 * @c: The character to search for
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
