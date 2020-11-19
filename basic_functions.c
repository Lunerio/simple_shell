#include "shell_header.h"

/**
 * _strlen - get char count
 * @s: string to analyze
 * Return: number of chars
 */

int _strlen(char *s)
{
	int index = 0;

	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

/**
 * add_node_end - Create new node
 * @head: pointer to head node
 * @str: string to add to node
 * Return: pointer to the node created
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode, *temp;
	int si;

	temp = *head;

	if (str == NULL)
	{
		return (0);
	}

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
	{
		return (0);
	}

	(*newnode).str = _strdup(str);
	(*newnode).next = NULL;

	if (*head == NULL)
	{
		(*head) = newnode;
		return (newnode);
	}

	while ((*temp).next)
	{
		temp = (*temp).next;
	}

	(*temp).next = newnode;
	return (newnode);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if both are the same
 */

int _strcmp(char *s1, char *s2)
{
	int index;
	int ch1;
	int ch2;

	for (index = 0; (s1[index] != '\0') || (s2[index] != '\0'); index++)
	{
		ch1 = s1[index];
		ch2 = s2[index];

		if (ch1 != ch2)
		{
			break;
		}
	}
	return (ch1 - ch2);
}

/**
 * _printenv - print every line of env
 */

void _printenv(void)
{
	extern char **environ;
	int i;
	size_t j;

	for (i = 0; environ[i] != 0; i++)
	{
		for (j = 0; environ[i][j] != 0; j++)
		{
		}
		write(1, environ[i], j);
		write(1, "\n", 1);
	}
}

char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	size_t j;
	int ch;

	for (i = 0; environ[i] != 0; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
		}
		ch = _strncmp(environ[i], name, j);
		if (ch == 0)
		{
			strtok(environ[i], "=");
			return (strtok(NULL, "="));
		}
	}
	return (NULL);
}
