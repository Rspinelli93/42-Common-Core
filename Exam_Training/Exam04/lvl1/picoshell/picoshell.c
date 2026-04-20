/*
Assignment name:	picoshell
Expected files:		picoshell.c
Allowed functions:	close, fork, wait, exit, execvp, dup2, pipe
___________________________________________________________________

Write the following function:

int    picoshell(char **cmds[]);

The goal of this function is to execute a pipeline. It must execute each
commands of cmds and connect the output of one to the input of the
next command (just like a shell).
e
Cmds contains a null-terminated list of valid commands. Each rows
of cmds are an argv array directly usable for a call to execvp. The first
arguments of each command is the command name or path and can be passed
directly as the first argument of execvp.

If any error occur, The function must return 1 (you must of course
close all the open fds before). otherwise the function must wait all child
processes and return 0. You will find in this directory a file main.c which
contain something to help you test your function.


Examples: 
./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell
./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
squblblb

___________________________________________________________________

Old summary by a student:
You are given a main function. It converts received arguments into cmds array
of strings. When there is a pipe the commands after the pipe are in the next
array of strings. You have to create a pipeline using the cmds you receive from
the main, and execute them. If there is any error the function should return 1.
Close all FFS before returning. If the cmds executed successfully wait all
child processes and return 0. */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	picoshell(char **cmds[])
{
	int		fd[2];
	int		prev_fd;
	int		i;
	int		children;
	int		ret;
	pid_t	pid;

	prev_fd = -1;
	i = 0;
	children = 0;
	ret = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}
			if (cmds[i + 1])
			{
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
				close(fd[0]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		children++;
		if (prev_fd != -1)
			close(prev_fd);
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
		i++;
	}
	while (children--)
	{
		int	status;

		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			ret = 1;
		if (WIFSIGNALED(status))
			ret = 1;
	}
	return (ret);
}
/*
TESTS:
# Basic
./picoshell /bin/ls "|" /usr/bin/grep picoshell

# 3 commands chained
./picoshell echo "squalala" "|" cat "|" sed 's/a/b/g'

# No pipe at all (single command)
./picoshell /bin/ls

# Command that produces no output (grep finds nothing)
./picoshell /bin/ls "|" /usr/bin/grep zzznomatch

# Invalid command (should return 1)
./picoshell /bin/notexist "|" cat

# Invalid second command
./picoshell /bin/ls "|" /bin/notexist

# Large output
./picoshell find / -maxdepth 3 "|" wc -l

# Binary in PATH (no full path)
./picoshell ls "|" grep main

# Many pipes
./picoshell ls "|" cat "|" cat "|" cat "|" grep main

# Empty input to second command
./picoshell echo "" "|" wc -c
*/

/*
How it works:
+ prev_fd tracks the read-end of the previous pipe (what the next child reads from).

Each iteration:
* 1. If there's a next command → pipe(fd) creates fd[0] (read) and fd[1] (write)
* 2. fork() → child sets up its I/O then execvp
* 3. Parent closes what it no longer needs, saves fd[0] as prev_fd for next iteration

The pipe chain visually:
 - cmd[0] → fd[1] | fd[0] → cmd[1] → fd[1] | fd[0] → cmd[2]

Key points:
 - Child: dup2(prev_fd, STDIN) = read from previous pipe, dup2(fd[1], STDOUT) = write to next pipe
 - Parent must close fd[1] after fork, otherwise the next child never gets EOF on its stdin
 - while (wait(NULL) != -1) reaps all children — don't use a counter, just wait until error

Common mistakes to avoid:
 - Forgetting to close(prev_fd) in parent after fork → fd leak
 - Not closing fd[0] in child when it writes → pipe never closes downstream
 - Only waiting for last child → zombie processes*/