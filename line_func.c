#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

/**
 * execute_line - Parses the command line looking for commands and argumements.
 *
 * Return 0 on success
 */

char *execute_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t n_bytes;

	printf("#cisfun$:");

	n_bytes = getline(&line, &bufsize, stdin);
	line[n_bytes - 1] = '\0';
	
	/*printf("%s\n", line);*/
	return (line);
}

/**
 * to_arg - recieves strings and turn it into array of args
 * Return : array of string 
 *
 */
char **to_args(char *cmdstr)
{
	char *str = NULL;
	char **args = NULL;
	size_t max_args = 7;
	size_t args_count = 0;
	char *delim = " ";

	args = malloc(sizeof(*args) * max_args);

	str = strtok(cmdstr, delim);

	while (str && args_count < max_args - 1)
	{
		args[args_count++] = str;
		str = strtok(NULL, delim);
	}

	args[args_count] = NULL;
	return(args);
}
