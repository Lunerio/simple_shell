#include "shell_header.h"

/**
 * main - calls functions for the simple shell
 * Return: returns 0 when finishes
 */

int main(void)
{
	char *string, **argv = NULL;
	int glcheck, a, cp;
	size_t buf = 0;

	while (1)
	{
		string = NULL;
		cp = p_prompt();
		glcheck = getline(&string, &buf, stdin);

		a = checker(glcheck, string);
		if (a == 2) /*exit condition*/
			return(0);
		if (a == 3) /*new line*/
			write(1, "\n", 1);
		if (a == 1) /*in case of -1 in getline*/
			perror("Error");
		if (a == 4)
		{
			free(string);
			continue;
		}
		else
		{
		        argv = tokenizer(string);
			exec(argv, string);
		}
	}
	if (cp == 0)
	{
		write(1, "\n", 1);
	}
	return (0);
}
