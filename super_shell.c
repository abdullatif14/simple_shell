#include "main.h"

/*
 * main - creating a simple super shell
 *
 * Return: 0
 */

int main(void)
{
	char *str, *buffer;
	char *av[2];
	size_t buffsize = 120;
	int i, j = 0, k = 0;
	pid_t pid;
	int status;

	buffer = malloc(sizeof(char) * buffsize);

	while (1)
	{
		printf("$ ");
		i = getline(&buffer, &buffsize, stdin);
		if (i == -1)
		{
			printf("\n");
			break;
		}
		str = malloc(sizeof(char) * (i + 1));
		while (buffer[j] != '\0' && buffer[j] != '\n')
		{
			str[k] = buffer[j];
			k++;
			j++;
		}
		str[k] = '\0';
		k = 0;
		j = 0;

		av[0] = str;
		av[1] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				perror("error");
			exit(0);
		}
		
		else
		{
			wait(&status);
		}
	}
	return (0);
}
