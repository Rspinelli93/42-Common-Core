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
#include <stdio.h>
#include <sys/types.h>

void	close_both(int fd[])
{
	close(fd[0]);
	close(fd[1]);
}

int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	pid_t pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	if ((pid = fork()) == -1)
		return (close_both(fd), -1);
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], 1) == -1);
			{
				close(fd[1]);
				exit(1);
			}
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			if (dup2(fd[0], 0) == -1);
			{
				close(fd[0]);
				exit(1);
			}
			close(fd[0]);
		}
		execvep(file, argv);
		exit(1);
	}
	if (type == 'r')
		return (close(fd[1]), fd[0]);
	return (close(fd[0]), fd[1]);
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
