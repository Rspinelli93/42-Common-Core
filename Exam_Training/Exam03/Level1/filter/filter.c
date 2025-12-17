#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 2

int     ft_strlen(char *str);
char    *str_realloc(char *str, char *buffer);
void print_string(char *str, char *av);

int main(int ac, char **av)
{
    char    *buff;
    char    *str;
    int     ret;

    // 1. Initialize str to empty "" so it's never NULL
    str = calloc(1, 1);
    if (!str)
        return (1);

    if (ac == 2)
    {
        // 2. Alloc buffer (Size + 1 for safety)
        buff = calloc(sizeof(char), BUFFER_SIZE + 1);
        if (!buff)
            return (free(str), 1);

        // 3. Read Loop
        while ((ret = read(STDIN_FILENO, buff, BUFFER_SIZE)) > 0)
        {
            buff[ret] = '\0'; // Just cap the string at ret. No loop needed.
            str = str_realloc(str, buff);
            int k = 0;
            while (buff[k])
            {
                if (buff[k] == '\n')
                {
                    // You might want to handle removing the \n if needed
                    break; 
                }
                k++;
            }
            if (buff[k] == '\n')
                break; // Break the main read loop
        }
        
        // 4. Handle Errors or Print
        if (ret == -1)
        {
            free(buff);
            free(str);
            return (perror("Error: "), -1);
        }
        print_string(str, av[1]); // str is safe now
        printf("\n");
        free(buff);
        free(str);
        return (0);
    }
    free(str); // Don't forget to free if ac != 2
    return (1);
}

char    *str_realloc(char *str, char *buffer)
{
    char    *new_str;
    int     len_str;
    int     len_buff;
    int     i = 0;
    int     j = 0;

    // Calculate lengths to know exactly how much to alloc
    len_str = ft_strlen(str);
    len_buff = ft_strlen(buffer);

    // Allocate new size (Old + New + 1 for \0)
    new_str = calloc(sizeof(char), len_str + len_buff + 1);
    if (!new_str)
        return (free(str), NULL); // Handle alloc fail

    // Copy part 1: The old string
    while (i < len_str)
    {
        new_str[i] = str[i];
        i++;
    }

    // Copy part 2: The new buffer
    while (j < len_buff)
    {
        new_str[i] = buffer[j];
        i++;
        j++;
    }
    
    // Null terminate
    new_str[i] = '\0';
    
    // Free the old string and return new one
    free(str);
    return (new_str);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str && str[i])
        i++;
    return (i);
}

void print_string(char *str, char *av)
{
    int i;
    int j;
    int k;

    i = 0;
    while (str[i])
    {
        j = 0;
        k = i;
        while (av[j])
        {
            if (av[j] == str[k])
                k++;
            j++;
        }
        if (j == k - i)
        {
            k = i;
            while (j != k - i)
            {
                str[k] = '*';
                k++;
            }
        }
        i++;
    }
    printf("%s", str);
}