#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	__pid_t pid;
	int 	fd[2];

	if (pipe(fd) == -1)
		return (1);

	pid = fork();
	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		close(fd[0]);
		write (fd[1], "hola", 4);
		close(fd[1]);
	}
	else
	{
		char str[5];
		memset(str, '\0', 5);
		close(fd[1]);
		read(fd[0], str, 5);
		printf("%s from child\n", str);
		close(fd[0]);
	}
	return (0);
}