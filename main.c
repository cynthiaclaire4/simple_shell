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
	char *cmd = NULL;
	char *args[] = {NULL, NULL};

	cmd = execute_line();

	args[0] = cmd;
	if (execve(args[0], args, NULL) < 0)
	{
		dprintf(STDERR_FILENO, "%s: command not found\n", args[0]);
	}
	return (0);
}
