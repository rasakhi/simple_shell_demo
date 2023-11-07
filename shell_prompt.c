#include "main.h"

/**
 * shell_prompt - displays shell prompt and takes commands from user
 * @av: arguement vectors
 * @env: environment vector
 * Return: Nothing
 */
void shell_prompt(char **av, char **env)
{
	char *command = NULL;
	char *argv[MAX];
	int i, status;
	pid_t child_process;
	size_t n = 0;
	ssize_t characters;

	while (1)
	{
		printf("cisfun$ ");
		characters = getline(&command, &n, stdin);
		if (characters == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (command[i])
		{
			if (command[i] == '\n')
				command[i] = '\0';
			i++;
		}
		argv[0] = command;
		child_process = fork();
		if (child_process == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (child_process == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
		{
			wait(&status);
		}
	}
}
