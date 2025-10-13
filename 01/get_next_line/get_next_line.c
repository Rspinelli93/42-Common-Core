/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:03 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/13 16:18:40 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
$	READ()

?	ssize_t read(int fd, void *buf, size_t nbyte);
	This function attempts to read nbyte bytes of data from the
	object referenced by the descriptor fd into the buffer
	pointed to by buf.  The read() function starts at a position
	given by the pointer associated with fd. At the end, the
	pointer is incremented by the number of bytes (nbyte) actually read.
*	Return
	On success, the number of bytes read is returned (zero indicates
    end of file), and the file position is advanced by this number.
	It is not an error if this number is smaller than the number of
    bytes requested; this may happen when fewer bytes are actually available.

$	OPEN:

?	int open(const char *path, int oflag, ... );

*Flags:
You have to tell your function what kind of access you want.

?    O_RDONLY: In read-only mode, open the file.
?    O_WRONLY: In a write-only mode, open the file
?    O_RDWR: Open the file in reading and write mode
?    O_CREAT: This flag is applied to create a file if it
?		doesn’t exist in the specified path or directory
?    O_EXCL: Prevents the file creation if it already
?		exists in the directory or location.

*Return:
The return value of open() is a file descriptor, a small,
nonnegative integer that is an index to an entry in the
process's table of open file descriptors. If there is an error somewhere,
the function will return -1 as a synonym of failure.
?	fd = open("text.txt", O_RDONLY);
*/
/*
When writing your tests, remember that:
1) Both the buffer size and the line size can be of very different
values.
2) A file descriptor does not only point to regular files.
Be thorough and cross-check your work with your peers. Prepare a
comprehensive set of diverse tests for the defense.When writing your tests,
remember that:
1) Both the buffer size and the line size can be of very different
values.
2) A file descriptor does not only point to regular files.
Be thorough and cross-check your work with your peers. Prepare a
comprehensive set of diverse tests for the defense.
*/

/*
$	IMPLEMENTATION

	- Allocate the buffer
	- Read the document.
	- Store in the buffer.
	- Copy the values of the buffer inside the static until
		static contains \n or the iteration of buffer is
		smaller than the size buffer (meaning we got till the
		end of the document).
	- Copy the values of the static until the \n into another
		string to return. Advance the static until \n + 1
		(This will have the static ready fo the next iteration).
*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;
	int			ret;

	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (fd < 0 || !buff || BUFFER_SIZE < 1)
		return (NULL);
	while (!contains_n(stash))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		stash = concat_end(stash, buff);
		if (ret < BUFFER_SIZE)
			return (stash);
	}
	line = get_lines(stash);
	stash = str_realloc(stash, 0, ft_strlen(line) - 1);
	return (line);
}

/*
	* get_line() will allocate and copy a string until finding
	* a '\n' character and return the newly allocated string. */
char	*get_lines(char *str)
{
	char	*line;
	char	*ptr;
	int		len;

	len = 0;
	while (str[len] != '\n')
		len++;
	line = ft_calloc(sizeof(char), len + 2);
	ptr = line;
	while (len > 0)
	{
		*ptr = *str;
		ptr++;
		str++;
		len--;
	}
	return (line);
}

/*
	* concat_end concatenates at the end of stash, the buffer.
	* returns a newly reallocated stash with the buffer concat
	* in it or NULL if no memory available. */
char	*concat_end(char *stash, char *buff)
{
	char	*ptr;

	if (!stash)
	{
		stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		ptr = stash;
	}
	else
	{
		stash = str_realloc(stash, BUFFER_SIZE, 0);
		if (!stash)
			return (NULL);
		ptr = stash + (ft_strlen(stash));
	}
	while (*buff)
	{
		*ptr = *buff;
		ptr++;
		buff++;
	}
	return (stash);
}

/*
	* str_realloc() allocates in memory a new string, coping each byte of str
	* into the new string from index "ix". The memory is allocatd acording the
	* bytes needed to copy + b_size (buffer size).
	* RETURN: frees the old string and returns the new one. */
char	*str_realloc(char *str, int b_size, int ix)
{
	char	*new;
	int		i;
	int		slen;

	i = ix;
	slen = 0;
	while (str[ix])
	{
		slen++;
		ix++;
	}
	new = ft_calloc(sizeof(char), slen + b_size + 1);
	ix = i;
	i = 0;
	while (str[ix])
	{
		new[i] = str[ix];
		i++;
		ix++;
	}
	free(str);
	return (new);
}

int	main(void)
{
	int	fd;
	char *str;
	int i = 15;

	fd = open("./test.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	while (--i > 0)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
}
