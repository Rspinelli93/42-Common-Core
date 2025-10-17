/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:03 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/17 20:48:12 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

* Flags:
You have to tell your function what kind of access you want.

?    O_RDONLY: In read-only mode, open the file.
?    O_WRONLY: In a write-only mode, open the file
?    O_RDWR: Open the file in reading and write mode
?    O_CREAT: This flag is applied to create a file if it
?		doesn’t exist in the specified path or directory
?    O_EXCL: Prevents the file creation if it already
?		exists in the directory or location.

* Return:
The return value of open() is a file descriptor, a small,
nonnegative integer that is an index to an entry in the
process's table of open file descriptors. If there is an error somewhere,
the function will return -1 as a synonym of failure.
?	fd = open("text.txt", O_RDONLY);
*/
/*
$	IMPLEMENTATION

	? Check edge cases:
		- fd fail to read
		- buffer size bigger than 0
		- read condition: this check lets us see if the file exists and
      		that it has some content to read from, or event that the file is 
    		openable to read, maybe the file descriptor is more than 0, but it
			was open in 'modify only', that means we can't read it.
	? Allocate the buffer
	? Read the document.
	? Store in the buffer.
	- Copy the values of the buffer inside the static until
		static contains \n or the iteration of buffer is
		smaller than the size buffer (meaning we got till the
		end of the document).
	- Copy the values of the static until the \n into another
		string to return. Advance the static until \n + 1
		(This will have the static ready fo the next iteration).
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
        return (NULL);
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!stash)
		stash = NULL;
	while (contains_c(stash, '\n') < 0 || read(fd, buff, BUFFER_SIZE) != 0)
	{
		read(fd, buff, BUFFER_SIZE);
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (free(buff), NULL);
	}
	if (contains_c(stash, '\n') != -1) //containting \n case
	{
		stash = ft_substr(stash, (contains_c(stash, '\n') + 1), ft_strlen(stash));
		line = new_strdup(stash);
		if (!line)
			return (free(buff), NULL);
		return (free(buff), line);
	}
	else
		return (free(buff), stash);
}
/*
	* Function to check if the str contains c. 
	* Return value is the index of the char or -1 in case
	* of not finding it.*/
int	contains_c(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (-1);
}

int	main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char	*str = get_next_line(fd);
	printf("%s", str);
	free(str);
	char	*str2 = get_next_line(fd);
	printf("%s", str2);
	free(str2);
}
