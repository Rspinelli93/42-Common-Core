#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int ft_strlen(char *str)
{

}

char *ft_strchr(char *str, char c)
{

}

char *ft_strjoin(char *str, char *buff)
{

}

void save_buff(char *line, char *buff)
{

}

char *get_next_line(int fd)
{
	char buff[BUFFER_SIZE + 1];
	char *line = NULL;
	int ret = 0;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(line, buff);
	while (!ft_strchr(line, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 1)
			break;
		buff[ret] = '\0';
		ft_strjoin(line, buff);
		buff[0] = '\0';
	}
	buff[0] = '\0';
	save_buff(line, buff);
	return (line);
}
