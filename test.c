/*
cc test.c -Wall -Wextra -Werror -L . -l ft -I include -o test

-g
    add for debbuging, then run gdb ./a.out

-I dir
    Add directory dir to the list of directories to be searched for header files.

-L dir
    Add directory dir to the list of directories to be searched for library files.

-l lib
    Link with the library named lib. The compiler searches for liblib.a or liblib.so.  
*/

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    printf("--------- ATOI ---------\n");
    printf("%i - ", atoi("Hola"));
    printf("%i\n", ft_atoi("Hola"));
    printf("%i - ", atoi(" \t+55p"));
    printf("%i\n", ft_atoi(" \t+55p"));
    printf("%i - ", atoi(""));
    printf("%i\n", ft_atoi(""));
    printf("%i - ", atoi("42"));
    printf("%i\n", ft_atoi("42"));
    printf("%i - ", atoi("  \t \v -42asdasd"));
    printf("%i\n", ft_atoi("  \t \v -42asdasd"));
    printf("--------- ATOI ---------\n\n");

    printf("--------- BZERO ---------\n");
    char* str1 = malloc(3);
    char* str2 = malloc(3);
    char* temp1 = str1 + 1;
    char* temp2 = str2 + 1;
    int x = 97;
    int i = 0;

    while (i < 3)
    {
        str1[i] = x;
        str2[i] = x;
        x++;
        i++;
    }
    printf("%s - ", str1);
    printf("%s\n", str2);
    bzero(temp1, 1);
    ft_bzero(temp2, 1);
    printf("%s - ", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
    printf("--------- BZERO ---------\n\n");

    printf("--------- CALLOC ---------\n");
    int* arr = ft_calloc(35, sizeof(int));
    int j = 0;
    while (j < 35)
    {
        printf("%i ", arr[j]);
        j++;
    }
    free(arr);
    printf("\n--------- CALLOC ---------\n\n");

    printf("--------- ISALNUM ---------\n");
    printf("%i - ", isalnum('5'));
    printf("%i\n", ft_isalnum('5'));
    printf("%i - ", isalnum('['));
    printf("%i\n", ft_isalnum('['));
    printf("%i - ", isalnum('#'));
    printf("%i\n", ft_isalnum('#'));
    printf("%i - ", isalnum('Q'));
    printf("%i\n", ft_isalnum('Q'));
    printf("%i - ", isalnum(-5));
    printf("%i\n", ft_isalnum(-5));
    printf("%i - ", isalnum('z'));
    printf("%i\n", ft_isalnum('z'));
    printf("%i - ", isalnum('@'));
    printf("%i\n", ft_isalnum('@'));
    printf("%i - ", isalnum('Z'));
    printf("%i\n", ft_isalnum('Z'));
    printf("%i - ", isalnum(-32));
    printf("%i\n", ft_isalnum(-32));
    printf("%i - ", isalnum(1500));
    printf("%i\n", ft_isalnum(1500));
    printf("--------- ISALNUM ---------\n\n");

    printf("--------- ISALPHA ---------\n");
    printf("%i - ", isalpha('5'));
    printf("%i\n", ft_isalpha('5'));
    printf("%i - ", isalpha('['));
    printf("%i\n", ft_isalpha('['));
    printf("%i - ", isalpha('#'));
    printf("%i\n", ft_isalpha('#'));
    printf("%i - ", isalpha('Q'));
    printf("%i\n", ft_isalpha('Q'));
    printf("%i - ", isalpha(-5));
    printf("%i\n", ft_isalpha(-5));
    printf("%i - ", isalpha('z'));
    printf("%i\n", ft_isalpha('z'));
    printf("%i - ", isalpha('@'));
    printf("%i\n", ft_isalpha('@'));
    printf("%i - ", isalpha('Z'));
    printf("%i\n", ft_isalpha('Z'));
    printf("%i - ", isalpha(-32));
    printf("%i\n", ft_isalpha(-32));
    printf("%i - ", isalpha(1500));
    printf("%i\n", ft_isalpha(1500));
    printf("--------- ISALPHA ---------\n\n");

    printf("--------- ISASCII ---------\n");
    printf("%i - ", isascii(226));
    printf("%i\n", ft_isascii(226));
    printf("%i - ", isascii('['));
    printf("%i\n", ft_isascii('['));
    printf("%i - ", isascii('#'));
    printf("%i\n", ft_isascii('#'));
    printf("%i - ", isascii('p'));
    printf("%i\n", ft_isascii('p'));
    printf("%i - ", isascii(-5));
    printf("%i\n", ft_isascii(-5));
    printf("%i - ", isascii('z'));
    printf("%i\n", ft_isascii('z'));
    printf("%i - ", isascii('\b'));
    printf("%i\n", ft_isascii('\b'));
    printf("%i - ", isascii('Z'));
    printf("%i\n", ft_isascii('Z'));
    printf("%i - ", isascii(-32));
    printf("%i\n", ft_isascii(-32));
    printf("%i - ", isascii(1500));
    printf("%i\n", ft_isascii(1500));
    printf("--------- ISASCII ---------\n\n");

    printf("--------- ISDIGIT ---------\n");
    printf("%i - ", isdigit(226));
    printf("%i\n", ft_isdigit(226));
    printf("%i - ", isdigit('0'));
    printf("%i\n", ft_isdigit('0'));
    printf("%i - ", isdigit('7'));
    printf("%i\n", ft_isdigit('7'));
    printf("%i - ", isdigit('p'));
    printf("%i\n", ft_isdigit('p'));
    printf("%i - ", isdigit(-5));
    printf("%i\n", ft_isdigit(-5));
    printf("%i - ", isdigit('z'));
    printf("%i\n", ft_isdigit('z'));
    printf("%i - ", isdigit('\b'));
    printf("%i\n", ft_isdigit('\b'));
    printf("%i - ", isdigit('Z'));
    printf("%i\n", ft_isdigit('Z'));
    printf("%i - ", isdigit(-32));
    printf("%i\n", ft_isdigit(-32));
    printf("%i - ", isdigit(1500));
    printf("%i\n", ft_isdigit(1500));
    printf("--------- ISDIGIT ---------\n\n");

    printf("--------- ISPRINT ---------\n");
    printf("%i - ", isprint(226));
    printf("%i\n", ft_isprint(226));
    printf("%i - ", isprint('0'));
    printf("%i\n", ft_isprint('0'));
    printf("%i - ", isprint('7'));
    printf("%i\n", ft_isprint('7'));
    printf("%i - ", isprint('p'));
    printf("%i\n", ft_isprint('p'));
    printf("%i - ", isprint(-5));
    printf("%i\n", ft_isprint(-5));
    printf("%i - ", isprint('z'));
    printf("%i\n", ft_isprint('z'));
    printf("%i - ", isprint('\b'));
    printf("%i\n", ft_isprint('\b'));
    printf("%i - ", isprint('Z'));
    printf("%i\n", ft_isprint('Z'));
    printf("%i - ", isprint(-32));
    printf("%i\n", ft_isprint(-32));
    printf("%i - ", isprint(1500));
    printf("%i\n", ft_isprint(1500));
    printf("--------- ISPRINT ---------\n\n");

    printf("--------- STRLEN ---------\n");
    printf("%li - ", strlen("Hola"));
    printf("%li\n", ft_strlen("Hola"));
    printf("%li - ", strlen("A"));
    printf("%li\n", ft_strlen("A"));
    printf("%li - ", strlen(""));
    printf("%li\n", ft_strlen(""));
    printf("%li - ", strlen("42"));
    printf("%li\n", ft_strlen("42"));
    printf("%li - ", strlen("qwertzuiopasdfghjklyxcvbnmqwertzuioasdfghjklyxcvbnm"));
    printf("%li\n", ft_strlen("qwertzuiopasdfghjklyxcvbnmqwertzuioasdfghjklyxcvbnm"));
    printf("--------- STRLEN ---------\n\n");

    printf("--------- STRRCHR ---------\n");
    printf("%s - ", strrchr("aaabaaa", 'b'));
    printf("%s\n", ft_strrchr("aaabaaa", 'b'));
    // printf("%s - ", strrchr("aaabaaa", 'x'));
    // printf("%s\n", ft_strrchr("aaabaaa", 'x'));
    printf("%s - ", strrchr("hola", 'o'));
    printf("%s\n", ft_strrchr("hola", 'o'));
    printf("%s - ", strrchr("dogScat", 'S'));
    printf("%s\n", ft_strrchr("dogScat", 'S'));
    printf("%s - ", strrchr("[right]", '['));
    printf("%s\n", ft_strrchr("[right]", '['));
    printf("%s - ", strrchr("?42", '4'));
    printf("%s\n", ft_strrchr("?42", '4'));
    printf("--------- STRRCHR ---------\n\n");

    printf("--------- TOLOWER ---------\n");
    printf("%i - ", tolower(226));
    printf("%i\n", ft_tolower(226));
    printf("%i - ", tolower('0'));
    printf("%i\n", ft_tolower('0'));
    printf("%i - ", tolower('7'));
    printf("%i\n", ft_tolower('7'));
    printf("%i - ", tolower('p'));
    printf("%i\n", ft_tolower('p'));
    printf("%i - ", tolower(-500));
    printf("%i\n", ft_tolower(-500));
    printf("%i - ", tolower('A'));
    printf("%i\n", ft_tolower('A'));
    printf("%i - ", tolower('\b'));
    printf("%i\n", ft_tolower('\b'));
    printf("%i - ", tolower('Z'));
    printf("%i\n", ft_tolower('Z'));
    printf("%i - ", tolower(1500));
    printf("%i\n", ft_tolower(1500));
    printf("--------- TOLOWER ---------\n\n");

    printf("--------- TOUPPER ---------\n");
    printf("%i - ", toupper(226));
    printf("%i\n", ft_toupper(226));
    printf("%i - ", toupper('0'));
    printf("%i\n", ft_toupper('0'));
    printf("%i - ", toupper('7'));
    printf("%i\n", ft_toupper('7'));
    printf("%i - ", toupper('p'));
    printf("%i\n", ft_toupper('p'));
    printf("%i - ", toupper(-255));
    printf("%i\n", ft_toupper(-255));
    printf("%i - ", toupper('A'));
    printf("%i\n", ft_toupper('A'));
    printf("%i - ", toupper('\t'));
    printf("%i\n", ft_toupper('\t'));
    printf("%i - ", toupper('x'));
    printf("%i\n", ft_toupper('x'));
    printf("%i - ", toupper(1500));
    printf("%i\n", ft_toupper(1500));
    printf("--------- TOUPPER ---------\n\n");

    return (0);
}