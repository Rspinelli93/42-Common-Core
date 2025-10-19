/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:03 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/19 12:34:24 by rspinell         ###   ########.fr       */
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

#include "get_next_line.h"

/* Returns the length of a string */
int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

/*
	* BOOL. Function to check if the string
	* contains a new line char ('\n'). */
int	contains_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
	* Allocates memory, filling bytes with 0s */
void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
	* Fills bytes with 0s */
void	ft_bzero(void *s, int n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = '\0';
		n--;
		str++;
	}
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	char	*src;

	len = ft_strlen(s);
	src = (char *)s;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return ((void *) NULL);
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest - len);
}
/* -------------------------------------------------------------------------------------------------- */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;
	int			ret;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
        return (NULL);
    buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (!contains_n(stash))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == 0 && stash == NULL)
			return (free(buff), NULL);
		stash = concat_end(stash, buff);
		if (!stash)
			return (free(buff), NULL);
		if (ret < BUFFER_SIZE)
		{
			line = ft_strdup(stash);
			return (free(buff), free(stash), line);
		}
	}
	line = get_lines(stash);
	stash = new_stash(stash);
	return (free(buff), line);
}

/*
	* get_line() will allocate and copy a string until finding
	* a '\n' character and return the newly allocated string. */
char	*get_lines(char *str)
{
	char	*line;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[len] != '\n')
		len++;
	line = ft_calloc(sizeof(char), (len + 2));
	if (line == NULL)
		return (NULL);
	while (i <= len)
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

/*
	* concat_end concatenates at the end of stash, the buffer.
	* returns a newly reallocated stash with the buffer concat
	* in it or NULL if no memory available. */
char	*concat_end(char *stash, char *buff)
{
	int		ix;
	int		j;

	j = 0;
	if (!stash)
	{
		stash = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (stash == NULL)
			return (NULL);
		ix = 0;
	}
	else
	{
		ix = ft_strlen(stash);
		stash = str_realloc(stash);
		if (!stash)
			return (NULL);
	}
	while (buff[j])
	{
		stash[ix] = buff[j];
		ix++;
		j++;
	}
	return (stash);
}

/*
	* str_realloc() allocates in memory a new string, coping each byte of str
	* into the new string + BUFFER_SIZE '\0' bytes.
	* RETURN: frees the old string and returns the new one. */
char	*str_realloc(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), (ft_strlen(str) + BUFFER_SIZE + 1));
	if (new == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}

/*
	* function to get a new stash right after returning each line.
	* it will free the old stash and reallocate the new one with the string
	* right after the /n. */
char	*new_stash(char *str)
{
	char	*new;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	new = ft_calloc(sizeof(char), ft_strlen(str) - i);
	if (new == NULL)
		return (free(str), NULL);
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
		new[j] = str[i];
		i++;
		j++;
	}
	return (free(str), new);
}

int	main(void)
{
	int fd = open("41_no_nl", O_RDONLY);
	printf("fd: %d\n", fd);
	char *str;
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	free(str);
}
