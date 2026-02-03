// Assignment name: filter
// Expected files: filter.c
// Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
// realloc, free, printf, fprintf, stdout, stderr, perror
// --------------------------------------------------------------------------------

// Write a program that will take one and only one argument.

// Your program will then read from stdin and write all the content read in stdout
// except that every occurrence of s must be replaced by '*' (as many as the length
// of s). Your program will be tested with random buffer sizes, using a custom read
// function. Therefore the buffer being set in your program will be filled with a
// different number of chars each new call.


// For example:

// ./filter bonjour
// will behave in the same way as:
// sed 's/bonjour/*******/g'

// ./filter abc
// will behave in the same way as:
// sed's/abc/***/g'

// More generally your program must be the equivalent of the shell script filter.sh
// present in this directory (you can compare your program with it).

// In case of error during a read or a malloc, you must write "Error: " followed by
// the error message in stderr and return 1.

// If the program is called without arguments or with an empty argument or with multiple
// arguments, it must return 1.

// For example this should work:

// $> echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
// ***defaaa***de******d***$
// $> echo 'ababcabababc' | ./filter ababc | cat -e
// *****ab*****$
// $>

// NOTES:
// memmem includes:
//                 #define _GNU_SOURCE
// 			    #include <string.h>

// perror includes:
//                 #include <errno.h>

// read includes:
//                 #include <fcntl.h>

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int	ft_strcmp(char *str, char *occ, int size)
{
	int i = 0;

	while (occ[i] == str[i] && str[i] && occ[i] && i < size)
		i++;
	if (occ[i] == '\0')
		return (1);
	return (0);
}

void set_asterix(char *str, int size)
{
	int i = 0;

	while (size > i && str[i])
	{
		str[i] = '*';
		i++;
	}
}

char *ft_filter(char *string, char *occ)
{
	int size = strlen(occ);
	char *str = string;
	if (!string)
		return (NULL);
	while(str && *str)
	{
		if (ft_strcmp(str, occ, size))
		{
			set_asterix(str, size);
			str += size;
		}
		if (*str == '\0')
			break;
		str++;
	}
	return (string);
}

int main(int ac, char **av)
{
	char buff[1000000];
	int i = 0;
	int ret;

	if(ac != 2 || av[1][0] == '\0')
		return (1);
	while ((ret = read(0, buff + i, 10)) > 0)
	{
		i = i + ret;
		buff[i] = '\0';
	}
	printf("%s", ft_filter(buff, av[1]));
	return (1);
}

// int main(void)
// {
// 	printf("%s\n", ft_filter(ft_strdup("hola abcdefg"), "abc"));
// 	return (0);
// }
