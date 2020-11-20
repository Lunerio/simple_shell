#include "shell_header.h"

/**
 * _strncmp - check the code for Holberton School students.
 * @s1: pointer to s1
 * @s2: pointer to s2
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
