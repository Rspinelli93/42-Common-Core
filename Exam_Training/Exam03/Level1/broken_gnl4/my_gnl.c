#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 5

int ft_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, char c)
{
    char *ptr;

    if (!str)
        return (NULL);
    ptr = str;
    while (*ptr)
    {
        if (*ptr == c)
            return (ptr);
        ptr++;
    }
    if (*ptr == c)
        return (ptr);
    return (NULL);

}

char    *ft_strjoin(char *line, char *buff)
{
    char *new = NULL;
    int len = 0;
    int i = 0;
    int j = 0;

    if (!line && !buff)
        return (new);
    len = ft_strlen(line) + ft_strlen(buff) + 1;
    new = malloc(sizeof(char) * len);
    if (!new)
    {
        if (line)
            free(line);
        return (NULL);
    }
    while (line && line[j])
    {
        new[i] = line[j];
        i++; j++;
    }
    j = 0;
    while (buff && buff[j])
    {
        new[i] = buff[j];
        i++; j++;
    }
    new[i] = '\0';
    if (line)
        free(line);
    return (new);
}

static void    save_buff(char *line, char *buff)
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
        i++;
        ptr++;
    }
    buff[i] = '\0';
}

char    *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1];
    char ret = 0;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    line = ft_strjoin(line, buff);
    while (!ft_strchr(line, '\n'))
    {
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret < 1)
            break ;
        buff[ret] = '\0';
        line = ft_strjoin(line, buff);
        buff[0] = '\0';
    }
    buff[0] = '\0';
    save_buff(line, buff);
    return (line);
}

int main(void)
{
    int fd;
    char *str;

    fd = open("/home/rick/Documents/Common-Core/Lvl01/gnl/tests/files/test_alternate_multiple_new_line", O_RDONLY);
    str = get_next_line(fd);
    if (!str)
        return (1);
    while (str && *str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    if (str) 
        free(str);
    close(fd);
    return (1);
}