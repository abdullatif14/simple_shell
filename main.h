#ifndef _MAIN_H
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char **argv);
char *get_location(char *command);

typedef struct varibles 
{
	char **env;
}vars_t;

#endif /*main_h*/
