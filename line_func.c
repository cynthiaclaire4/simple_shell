#include<stdio.h>
#include<stdlib.h>
/**
 * execute_line - Parses the command line looking for commands and argumements.
 *
 * Return 0 on success

char *execute_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t n;

	printf("#cisfun$");

	if ((n = getline(&line, &bufsize, stdin) == -1))
	{
		if (feof(stdin))  /** serach for end of file**/
		{
			exit(EXIT_SUCCESS);
		}
		else
			perror("readline problem");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", line);
	return (line);
}
