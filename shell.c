#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "main.h"

/*
 * main - body of the program
 */
int main(int ac, char **av)
{
	char *cmdstr = NULL;
	char **args = NULL;

	while (1)
	{
		if (ac > 1)
			args = av + 1;
		else
		{
			/* read command from user */
			cmdstr = execute_line();
			/*change command into arg of strings */
			args = to_args(cmdstr);
		}

		/*execute commands */
		execve(args[0], args, NULL);

		dprintf(STDERR_FILENO, "%s: command not found\n", args[0]);
	}
	return (0);
}
