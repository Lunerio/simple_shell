#include "shell_header.h"

/**
 * _strncmp - check the code for Holberton School students.
 * @s1: pointer to s1
 * @s2: pointer to s2
 * @n: limit of bytes to read
 * Return: Always 0.
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	unsigned int i;
	int ch1;
	int ch2;

	for (i = 0; ((s1[i] != '\0') || (s2[i] != '\0')) && (i < n); i++)
	{
		ch1 = s1[i];
		ch2 = s2[i];

		if (ch1 != ch2)
		{
			break;
		}
	}
	return (ch1 - ch2);
}

/**
 * _strdup - duplicate string
 * @str: pointer to str
 *Return: return pointer to malloc
 */

char *_strdup(char *str)
{
	char *s;
	int i;
	int size = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != 0; i++)
	{
		size++;
	}

	s = malloc(size * sizeof(char) + 1);

	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= size; i++)
	{
		s[i] = str[i];
	}

	return (s);
}

/**
 * p_prompt - Prints prompt on interactive mode
 * Return: 0 if interactive, 1 if non-interactive
 */

int p_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(1, "($) ", 4);
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * _strcpy - copy string from one pointer to a new one.
 * @dest: pointer to dest
 * @src: pointer to src
 * Return: New pointer.
 */

char *_strcpy(char *dest, char *src)
{

	int index = 0;
	int cuenta;

	while (src[index] != '\0')
	{
		index++;
	}

	for (cuenta = 0; cuenta <= index; cuenta++)
	{
		dest[cuenta] = src[cuenta];
	}
	return (dest);
}

/**
 * fargv - free the argv and all the index
 * @argv: double pointer with arguments
 */

void fargv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
