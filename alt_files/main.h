#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
<<<<<<< HEAD
#include <sys/stat.h>

void execmd(char **argv);
char *get_location(char *command);

typedef struct varibles 
{
	char **env;
}vars_t;


#endif /*main_h*/
