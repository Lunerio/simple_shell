#include "shell_header.h"

int main(void)
{
	char *string;
	char **argv = NULL;
	int glcheck, a;
	size_t buf = 0;

	while (1)
	{
		string = NULL;
		p_prompt();
		glcheck = getline(&string, &buf, stdin);

		a = checker(glcheck, string);
		if (a == 2)
			break;
		if (a == 3)
			write(1, "\n", 1);

		argv = tokenizer(string);
		exec(argv, string);
	}
	return (0);
}
