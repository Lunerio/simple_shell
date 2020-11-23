#include "shell_header.h"

char *chcommand(char *value, char *string)
{
	char *stok, *vtok, *t1, *t2;
	struct stat st;

	stok = strtok(string, " ");
	if (stat(stok, &st) == 0)
		return (string);
	vtok = strtok(value, ":");
	while (vtok != NULL)
	{
		t1 = _strcat(vtok, "/");
		t2 = _strcat(t1, stok);
		if (stat(t2, &st) == 0)
		{
			return (t2);
		}
		vtok = strtok(NULL, ":");
	}
	return (string);
}
