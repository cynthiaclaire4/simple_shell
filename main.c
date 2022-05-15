#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * main - Entry point of the program.
 * Return: Always 0.
 */

int main(void)
{
	char *cmdstr = NULL; /* command strings */
	char **args = NULL;;

	cmdstr = execute_line();

	args = to_args(cmdstr);
	if (execve(args[0], args, NULL) < 0)
	{
		dprintf(STDERR_FILENO, "%s: command not found\n", args[0]);
	}
	return (0);
}
