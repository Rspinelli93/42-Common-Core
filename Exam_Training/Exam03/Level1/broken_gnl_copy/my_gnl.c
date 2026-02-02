
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 5

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

int ft_strlen(char *str)
{
    int i = 0;
    while (str && str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *str, char *buff)
{
    char *new_str;
    int i = 0;
    int j = 0;
    int len;

    if (!str && !*buff)
        return (NULL);
    len = ft_strlen(str) + ft_strlen(buff) + 1;
    new_str = malloc(sizeof(char) * len);
    if (!new_str)
    {
        if (str)
            free(str);
        return (NULL);
    }
    while (str && str[j])
    {
        new_str[i] = str[j];
        i++;
        j++;
    }
    j = 0;
    while (buff && buff[j])
    {
        new_str[i] = buff[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (free(str), new_str);
}

static void line_to_buff(char *line, char *buff)
{
    char *ptr;
    int i = 0;
    if (!line)
        return ;
    ptr = ft_strchr(line, '\n');
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
    static char buff[BUFFER_SIZE + 1];
    char        *line = NULL;
    int         ret = 0;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    line = ft_strjoin(line, buff);
    while (!ft_strchr(line, '\n'))
    {
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret < 1)
            break;
        buff[ret] = '\0';
        line = ft_strjoin(line, buff);
        buff[0] = '\0';
    }
    buff[0] = '\0';
    line_to_buff(line, buff);
    return (line);
}

int main(void)
{
    int fd = open("/home/rick/Documents/Common-Core/Lvl01/gnl/tests/files/test_alternate_multiple_new_line", O_RDONLY);
    char *str;
    printf("%i\n", fd);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }
    close(fd);
}