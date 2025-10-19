/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:03 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/19 10:56:46 by rspinell         ###   ########.fr       */
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

/* ------------------------------------------------------------------------------- */

/*
	*Returns the length of a string */
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

/*
	* The strchr() function returns a pointer to the first occurrence of
	* the character c in the string s.
	* Also counts '\0' byte  to compare */
char	*ft_strchr(char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
	}
	if (*ptr == '\0' && (unsigned char) c == '\0')
		return (ptr);
	return (NULL);
}
/*
	* The strdup() function returns a pointer to a new string which is a
    * duplicate of the string s.
	* This version copies until the end of the string or until finding
	* a new line char, whichever happens first
	! Memory for the new string is obtained
    ! with malloc(3), and can be freed with free(3). */
char	*new_strdup(char *s)
{
	int		len;
	char	*dest;
	char	*src;

	len = ft_strlen(s);
	src = (char *)s;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return ((void *) NULL);
	while (*src || *src == '\n')
	{
		*dest = *src;
		src++;
		dest++;
	}
	if (*src == '\n')
	{
		*dest = *src;
		dest++;
	}
	*dest = '\0';
	return (dest - len);
}
/*
	* Concatenates two specified strings and returns the resulting string.
	$ s1 is free at the end
	! Memory for the new string is obtained
    ! with malloc(3), and can be freed with free(3). */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*dst;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *) malloc(sizeof(char) * len);
	if (!dst)
		return (free(s1), NULL);
	ptr = (char *) s1;
	while (*ptr)
	{
		*dst = *ptr;
		dst++;
		ptr++;
	}
	ptr = (char *) s2;
	while (*ptr)
	{
		*dst = *ptr;
		dst++;
		ptr++;
	}
	*dst = '\0';
	free(s1);
	return ((dst - (len - 1)));
}
/*
	* ft_substr returns a substring of the string s passed as parameter.

	* str: the string to take a substring from
	* start: starting position (index) of the extracted string
	* length: length of string to return
	! Memory for the new string is obtained
    ! with malloc(3), and can be freed with free(3). */
char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	char	*dst;
	int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (new_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ptr = (char *) s + start;
	i = 0;
	while (i < len)
	{
		*dst = *ptr;
		dst++;
		ptr++;
		i++;
	}
	*dst = '\0';
	return (dst - len);
}

/* ------------------------------------------------------------------------------- */

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
