#include "main.h"

/*
 * main - creating arguments that can be
 * passed in the command line
 * ac: number of arguments counted
 * av: argument vector or array of strings
 *
 * Return: success
 */

int main(int ac, char *av[])
{
	printf("argc: %d\n", ac);

	for (int i = 0; av[i]; i++)
		printf("argv[%d]: %s\n", i, av[i]);

	return (0);
}
