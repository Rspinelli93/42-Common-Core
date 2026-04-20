/*
Assignment name  : ft_popen
Expected files   : ft_popen.c
Allowed functions: pipe, fork, dup2, execvp, close, exit
--------------------------------------------------------------------------------------

Write the following function:

int ft_popen(const char *file, char *const argv[], char type);

The function must launch the executable file with the arguments argv (using execvp).
If type is 'r' the function must return a file descriptor connected to the output of the command.
If type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

For example, the function could be used like that:

int main()
{
    int  fd;
    char *line;

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
    while ((line = get_next_line(fd)))
        ft_putstr(line);
    return (0);
}


int	main() {
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
	char	*line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
}


Hints:
Do not leak file descriptors!
This exercise is inspired by the libc's popen(). */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	int		fd[2];
	pid_t	pid;

	if (type != 'r' && type != 'w')
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	close(fd[0]);
	return (fd[1]);
}

/*
How it works:
Two cases:
'r' (read from command output):
child stdout → fd[1] → pipe → fd[0] → parent reads
Child writes into fd[1], parent gets fd[0] to read.
'w' (write to command input):
parent writes → fd[1] → pipe → fd[0] → child stdin
Child reads from fd[0], parent gets fd[1] to write.
Key: parent always closes the end it doesn't use, child closes both after dup2.
Note: no wait() here — unlike picoshell, popen returns an fd for 
the caller to use. Waiting would block. The caller is 
responsible for reaping (real popen has pclose for that).*/
