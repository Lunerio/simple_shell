/*Functions for string length, creating nodes*/

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

	(*newnode).str = strdup(str);
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
