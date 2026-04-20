/*
Assignment name  : sandbox
Expected files   : sandbox.c
Allowed functions: fork, waitpid, exit, alarm, sigaction, kill, printf, strsignal,
errno, sigaddset, sigemptyset, sigfillset, sigdelset, sigismember
--------------------------------------------------------------------------------------

Write the following function:

#include <stdbool.h>
int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

This function must test if the function f is a nice function or a bad function, you
will return 1 if f is nice, 0 if f is bad or -1 in case of an error in your function.

A function is considered bad if it is terminated or stopped by a signal (segfault, abort...),
if it exit with any other exit code than 0 or if it times out.

If verbose is true, you must write the appropriate message among the following:
"Nice function!
"
"Bad function: exited with code <exit_code>
"
"Bad function: <signal description>
"
"Bad function: timed out after <timeout> seconds
"

You must not leak processes (even in zombie state, this will be checked using wait).

We will test your code with very bad functions.*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		alarm(timeout);
		f();
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		int sig = WTERMSIG(status);
		if (verbose)
		{
			if (sig == SIGALRM)
				printf("Bad function: timed out after %u seconds\n", timeout);
			else
				printf("Bad function: %s\n", strsignal(sig));
		}
		return (0);
	}
	if (WIFEXITED(status))
	{
		int code = WEXITSTATUS(status);
		if (code != 0)
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", code);
			return (0);
		}
	}
	if (verbose)
		printf("Nice function!\n");
	return (1);
}

void	nice_func(void)  { return; }
void	segfault(void)   { int *p = NULL; *p = 1; }
void	bad_exit(void)   { exit(42); }
void	infinite(void)   { while (1); }
void	abort_func(void) { abort(); }

int	main(void)
{
	sandbox(nice_func,  5, true);
	sandbox(segfault,   5, true);
	sandbox(bad_exit,   5, true);
	sandbox(infinite,   2, true);
	sandbox(abort_func, 5, true);
	/*
	Expected output:
	Nice function!
	Bad function: Segmentation fault
	Bad function: exited with code 42
	Bad function: timed out after 2 seconds
	Bad function: Aborted
	*/
	return (0);
}

/*
How it works:
fork() runs f() in a child. Parent just waitpids and reads the status.
WIFEXITED / WIFSIGNALED — these macros decode the status int 
that waitpid fills:

WIFSIGNALED(status) → child was killed by a signal (segfault, abort, alarm)
WTERMSIG(status) → which signal
WIFEXITED(status) → child called exit()
WEXITSTATUS(status) → what exit code

alarm(timeout) sends SIGALRM to the child after N seconds — so timeout 
is just another signal, handled the same way.*/