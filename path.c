#include "main.h"

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		 /* Duplicate the path string 
		  * remember to free up memory for this because 
		  *strdup allocates memory that needs to be freed*/
        	path_copy = strdup(path);
        /* Get length of the command that was passed */
        	command_length = strlen(command);

        /* Let's break down the path variable and get all the directories available*/
        	path_token = strtok(path_copy, ":");

		while(path_token != NULL)
		{
			/*Length of the directory*/
			directory_length = strlen(path_token);
			
			/*allocte memory*/

			file_path = malloc(command_length + directory_length + 2);

			/*NB : We added 2 for the slash and null character, we will introduce 
			 * in the full command */

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			/*lets text if the file path actually exists and return in
			 * otherwise try the next directory*/

			if (stat(file_path, &buffer) == 0)
			{
				/* returning 0 means success and the file is valid
				 *
				 * free the memory before returning file_path */

				free(file_path);

				path_token = strtok(NULL, ":");

			}
		}

		/* Return NULL if not found and free up memory*/

		free(path_copy);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}

		return (NULL);

	}

	return (NULL);
}
