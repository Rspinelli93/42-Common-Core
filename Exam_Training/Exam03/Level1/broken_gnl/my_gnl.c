# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <fcntl.h>
# define BUFFER_SIZE 5

//* ft_strlen()
// Count how many characters are in a string
// If the string is NULL, treat it as empty
// Start at index 0
// Move forward until we hit '\0'
// Return the number of characters counted
int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while (*str)
    {
        str++;
        i++;
    }
    return (i);
}
//* ft_strchr()
// Search for a specific character inside a string
// If the string is NULL, return NULL
// Scan each character one by one
// If the current character matches the target, return its address
// If we reach the end and didn’t find it, return NULL
char *ft_strchr(char *str, char c)
{
    if (!str)
        return (NULL);
    while (*str)
    {
        if (*str == c)
            return (str);
        str++;
    }
    return (NULL);
}

//* ft_strjoin(prev_line, buffer)
// Join two strings into a new one
// If prev_line is NULL and buffer is empty, return NULL
// Allocate enough memory to hold both strings plus '\0'
// If allocation fails, free prev_line and return NULL
// Copy prev_line into the new memory
// Append buffer after it
// Add a null terminator
// Free prev_line (it is no longer needed)
// Return the newly created string
char *ft_strjoin(char *prev, char *buffer)
{
    char *str;
    if (!prev && !*buffer)
        return (NULL);
    str = malloc(ft_strlen(prev) + ft_strlen(buffer) + 1);
    if (!str)
    {
        if (prev)
            free(prev);
        return (NULL);
    }
    int i = 0;
    int j = 0;
    while (prev && prev[i])
    {
        str[j] = prev[i];
        i++;
        j++;
    }
    i = 0;
    while (buffer && buffer[i])
    {
        str[j] = buffer[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return (str);
}

//* ft_line_to_state(state, line)
// Extract everything after the first '\n' in line
// Find the newline character in line
// If there is no newline, do nothing
// Move to the character right after '\n'
// Copy all remaining characters into state
// While copying, erase them from line
// Null-terminate state
// Now line contains only one full line
// And state contains leftover data for next call
static void extra_to_buff(char *buff, char *line)
{
    char *new_line = ft_strchr(line, '\n');
    int i = 0;

    if (!new_line)
        return ;
    new_line++;
    while (*new_line)
    {
        buff[i] = *new_line;
        i++;
        *new_line = '\0';
        new_line++;
    }
    buff[i] = '\0';
}

//* get_next_line(fd)
// Use a static buffer (state) to keep leftover data between calls
// If fd is invalid or BUFFER_SIZE is invalid, return NULL

// Start with line = NULL
// Add whatever is already in state to line

// While line does not contain '\n':
//     Read BUFFER_SIZE bytes from fd into state
//     If read returns 0 or error, stop
//     Null-terminate state
//     Append state to line
//     Clear state

// Clear state
// Move everything after the first '\n' from line into state
// Return line (which now contains exactly one line)
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char        *line = NULL;
    int         rd;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    line = ft_strjoin(line, buffer);
    while (!ft_strchr(line, '\n'))
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        if (rd < 1)
            break ;
        buffer[rd] = '\0';
        line = ft_strjoin(line, buffer);
        buffer[0] = '\0';
    }
    buffer[0] = '\0';
    extra_to_buff(buffer, line);
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