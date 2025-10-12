/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:03 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/12 16:40:52 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (fd < 0 || !buff)
		return (NULL);
	while (!found_n(line))
	{
		read(fd, buff, BUFFER_SIZE);
		concat_end(line, buff);
	}
	return (line);
}
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
comprehensive set of diverse tests for the defense.When writing your tests, remember that:
1) Both the buffer size and the line size can be of very different
values.
2) A file descriptor does not only point to regular files.
Be thorough and cross-check your work with your peers. Prepare a
comprehensive set of diverse tests for the defense.
*/