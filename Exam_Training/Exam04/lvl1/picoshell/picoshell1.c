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
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int    picoshell(char **cmds[])
{
	int fd[2];
	int prev_fd = -1;
	int i = 0;
	int children = 0;
	int ret = 0;
	pid_t pid;

	//* Parent
	while (cmds[i])
	{
		// If there is another command and then i do the pipe
		// and only continue if it doesnt fail
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
		// Fork the process, basically duplicate the process
		pid = fork();
		// Check if that didnt fail
		if (pid == -1)
			return (1);
		// if pid == 0 then its the child processs
		// everything inside this if is the chils process
		//* Child
		if (pid == 0)
		{
			// if there was a pipe before (so prev_fd was indeed
			// different than -1)
			if (prev_fd != -1)
			{
				// make stdin to point to the previous_fd
				// instead of reading from the keyboard, the child reads
				// from wherever the prev command wrote at
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit (1);
				close (prev_fd);
			}
			// if there is a next command
			if (cmds[i + 1])
			{
				// make stdout to change to the write into the pipe 
				// instead, then close them both
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
				close(fd[0]);
			}
			// run the commands with execvp, if execv returns is because it
			// failed, and i have to exit 1;
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		//* Parent
		// increase the children count
		children++;
		// Parent closes the pipe read, its given to the child process
		if (prev_fd != -1)
			close(prev_fd);
		// Parent closes the write end of the new pipe (only child wtires into it)
		// Save read end as prev_fd so next child can use it as stdin
		// next command
		if (cmds[i + 1])
		{
			close (fd[1]);
			prev_fd =  fd[0];
		}
		i++;
	}
	// Wait for each child to finish, one by one. 
	// -1 means "wait for any child". status captures how it exited.
	while (children--)
		wait(NULL);
	return (0);
}
