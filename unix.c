#include "main.h"

/** 
 * creating a unix shell interpreter
 */

/* attributes have the same function as void */
int main(__attribute__((unused))int ac,char **argv)
{
	/*declaring our variables*/
	char *prompt = "(MyShell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/*(void)delim, (void)lineptr_copy;*/
	/* creating an infinte loop*/
	while(1) 
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		/*checking if the getline function has reached EOF*/

		if (nchars_read == -1)
		{
			printf("The End...\n");
			return (-1);
		}

		/*allocate space for the lineptr copy*/
		
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("shit: memory error\n");
			return (-1);
		}
		/*copy lineptr to lineptr_copy*/
		strcpy(lineptr_copy, lineptr);

		/**
		 * first split the strings (lineptr) into 
		 * array of words
		 * then calculate the number of tokens
		 */
		
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/* Allocate space to hold the array of strings*/
		argv = malloc(sizeof(char *) * num_tokens);

		/*Store each token into argv array*/
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i],token);

			token = strtok(NULL, delim);
		}

		argv[i] = NULL;

		printf("%s\n", lineptr);
		/*free the memory after execution*/
		free(lineptr);
	}

	return (0);
}
