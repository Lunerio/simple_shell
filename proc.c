#include "shell_header.h"

int checker(int glcheck, char *string) /*devuelve un int al main para
retornar segun condiciones*/
{
     if (glcheck == -1)
     {
         if (glcheck == EOF)
         {
              free(string);
              return (2); /*for exiting*/
	 }
	 perror("Error");
	 free(string);
	 return (1); /*for error*/
     }

     if (string[0] == '\n')
     {
	     free(string);
	     return (3); /*print new line */
     }
     if (_strcmp(string, "exit\n") == 0)
     {
	     free(string);
	     return (2); /*for exiting*/
     }

     if (_strcmp(string, "env\n") == 0)
     {
	     _printenv();
	     return (4);
     }
     return (0);
}
