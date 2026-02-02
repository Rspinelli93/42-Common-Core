#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 5

int ft_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);

    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, char c)
{
    if (!str)
        return (NULL);
    while (*str)
    {
        if (*str == c)
            return (str);
        str++;
    }
    if (*str == c)
        return (str);
    return (NULL);
}

char    *ft_strjoin(char *line, char *buff)
{
    char *new;
    int len = ft_strlen(line) + ft_strlen(buff) + 1;
    int i = 0;
    int j = 0;

    if (!line && !*buff)
		return (NULL);
    new = malloc(sizeof(char) * len);
    if (!new)
    {
        if (line)
            free(line);
        return (NULL);
    }
    while (line && *line)
    {
        new[i] = line[j];
        i++;
        j++;
    }
    j = 0;
    while (buff && buff[i])
    {
        new[i] = buff[j];
        i++;
        j++;
    }
    new[i] = '\0';
    if (line)
        free(line);
    return (new);
}

static void save_buff(char *line, char *buff)
{
    char *ptr;
    int i = 0;
    ptr = ft_strchr(line, '\n');
    if (!ptr)
        return ;
    ptr++;
    while (*ptr)
    {
        buff[i] = *ptr;
        *ptr = '\0';
        ptr++;
        i++;
    }
    buff[i] = '\0';
}

char *get_next_line(int fd)
{
    int ret;
    char *line = NULL;
    static char buff[BUFFER_SIZE + 1];

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    line = ft_strjoin(line, buff);
    while (!ft_strchr(line, '\n'))
    {
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret < 1)
            break ;
        buff[ret] = 0;
        line = ft_strjoin(line, buff);
        buff[0] = '\0';
    }
    buff[0] = '\0';
    save_buff(line, buff);
    return (line);
}

int main(void)
{
    char *str;
    int fd = open("/home/rick/Documents/Common-Core/Lvl01/gnl/tests/files/test_alternate_multiple_new_line" ,O_RDONLY);
    while(str = get_next_line(fd))
    {
        printf("%s", str);
        free(str);
    }
    free(str);
    close(fd);
    return (0);
}