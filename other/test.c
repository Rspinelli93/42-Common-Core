/*
cc ./other/test.c -Wall -Wextra -Werror -L . -l ft -I include -o test

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

char    strmapitest(unsigned int i, char c);
char    toupermapi(unsigned int i, char c);
void    iteritest1(unsigned int i, char* s);
void    iteritest2(unsigned int i, char* s);

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

    printf("--------- MEMCHR ---------\n");
    int num = 88;
    printf("%p - ", memchr("Hola", 'x', 5));
    printf("%p\n", ft_memchr("Hola", 'x', 5));
    printf("%p - ", memchr("Hola", 'a', 4));
    printf("%p\n", ft_memchr("Hola", 'a', 4));
    printf("%p - ", memchr("", 'E', 1));
    printf("%p\n", ft_memchr("", 'E', 1));
    printf("%p - ", memchr("Hola", 'x', 0));
    printf("%p\n", ft_memchr("Hola", 'x', 0));
    printf("%p - ", memchr("chaU", 'c', 2));
    printf("%p\n", ft_memchr("chaU", 'c', 2));
    printf("%p - ", memchr(&num, 88, 4));
    printf("%p\n", ft_memchr(&num, 88, 4));
    printf("--------- MEMCHR ---------\n\n");

    printf("--------- MEMCMP ---------\n");
    int num2 = 88;
    int num3 = 5;
    printf("%i - ", memcmp("Hola", "Hola", 5));
    printf("%i\n", ft_memcmp("Hola", "Hola", 5));
    printf("%i - ", memcmp("Perro", "Gato", 5));
    printf("%i\n", ft_memcmp("Perro", "Perra", 5));
    printf("%i - ", memcmp("", "E", 1));
    printf("%i\n", ft_memcmp("", "E", 1));
    printf("%i - ", memcmp("Ex", "E", 2));
    printf("%i\n", ft_memcmp("Ex", "E", 2));
    printf("%i - ", memcmp("Hola", "asd", 0));
    printf("%i\n", ft_memcmp("Hola", "asd", 0));
    printf("%i - ", memcmp(&num2, &num, 4));
    printf("%i\n", ft_memcmp(&num2, &num, 4));
    printf("%i - ", memcmp(&num2, &num3, 4));
    printf("%i\n", ft_memcmp(&num2, &num3, 4));
    printf("--------- MEMCPM ---------\n\n");

    printf("--------- MEMCPY ---------\n");
    char* buffer = malloc(25);
    char* src = "Hola";
    buffer = ft_memcpy(buffer, src, 4);
    printf("%s\n", buffer);

    char* buffer1 = malloc(25);
    char* src1 = "I love this";
    buffer1 = ft_memcpy(buffer1, src1, 6);
    printf("%s\n", buffer1);

    char* buffer2 = malloc(25);
    char* src2 = "<<TEST>>";
    buffer2 = ft_memcpy(buffer2, src2, 9);
    printf("%s\n", buffer2);
    printf("--------- MEMCPY ---------\n\n");

    printf("--------- MEMMOVE ---------\n");
    char* src3 = "asdASD";
    int len3 = strlen(src3) + 1;
    char* dest3 = malloc(sizeof(char) * len3 - 3);
    dest3 = ft_memmove(dest3, src3 + 3, len3 - 3);
    printf("%s\n", dest3) ;

    char* src4 = "I love this (not this)";
    int len4 = 11;
    char* dest4  = malloc(sizeof(char) * len4);
    dest4  = ft_memmove(dest4 , src4, len4);
    printf("%s\n", dest4 );

    char* src5 = "<<TEST>>";
    int len5 = strlen(src5) + 1;
    char* dest5  = malloc(sizeof(char) * len5);
    dest5  = ft_memmove(dest5 , src5, len5);
    printf("%s\n", dest5 );
    printf("--------- MEMMOVE ---------\n\n");

    printf("--------- MEMSET ---------\n");
    char src6[] = "asdASD";
    ft_memset(src6, 'F', 3);
    printf("%s\n", src6) ;

    char src7[] = "I love this";
    ft_memset(src7 + 2 , '0', 4);
    printf("%s\n", src7 );

    char src8[] = "<<TEST>>";
    ft_memset(src8 + 2, '5', 4);
    printf("%s\n", src8 );
    printf("--------- MEMSET ---------\n\n");

    printf("--------- STRCHR ---------\n");
    char *src9 = "HolaXHola";
    char *dest9 = ft_strchr(src9, 'X');
    printf("%s\n", dest9) ;

    char *src11 = "HolaXChau";
    char *dest11 = ft_strchr(src11, 'H');
    printf("%s\n", dest11) ;
    
    char *src12 = "HolaXChau";
    char *dest12 = ft_strchr(src12, 'u');
    printf("%s\n", dest12) ;
    printf("--------- STRCHR ---------\n\n");

    printf("--------- STRDUP ---------\n");
    char *src13 = "Duplicate me";
    char *dest13 = ft_strdup(src13);
    printf("%s\n", dest13) ;
    free(dest13);

    char *src14 = "";
    char *dest14 = ft_strdup(src14);
    printf("%s\n", dest14);
    free(dest14);
    printf("--------- STRDUP ---------\n\n");

    printf("--------- STRLCAT ---------\n");
    char dest15[20] = "Hello, ";
    printf("Return %lu\n", ft_strlcat(dest15, "World!", sizeof(dest15)));
    printf("%s\n", dest15);
    char dest16[10] = "Hello, ";
    printf("Return %lu\n", ft_strlcat(dest16, "World!", sizeof(dest16)));
    printf("%s\n", dest16);
    printf("--------- STRLCAT ---------\n\n");

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

    printf("--------- STRNCMP ---------\n");
    printf("%i - ", strncmp("Hola", "Hola", 4));
    printf("%i\n", ft_strncmp("Hola", "Hola", 4));
    printf("%i - ", strncmp("x", "xyz", 1));
    printf("%i\n", ft_strncmp("x", "xyz", 1));
    printf("%i - ", strncmp("Ecole 42", "Ecole 421", 10));
    printf("%i\n", ft_strncmp("Ecole 42", "Ecole 421", 10));
    printf("%i - ", strncmp("Pedro", "Juan", 150));
    printf("%i\n", ft_strncmp("Pedro", "Juan", 150));
    printf("--------- STRNCMP ---------\n\n");

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
    
    printf("-------------------- EXTRAS -------------------\n");
    printf("-------------------- EXTRAS -------------------\n\n");

    printf("--------- SUBSTR ---------\n");
    printf("%s\n", ft_substr("Je ne comprends pas", 2, 5));
    printf("%s\n", ft_substr("Je ne comp\0 hi im hiding", 50, 150));
    printf("--------- SUBSTR ---------\n\n");

    printf("--------- STRJOIN ---------\n");
    printf("%s\n", ft_strjoin("Ecole", "42"));
    printf("%s\n", ft_strjoin("", ""));
    printf("%s\n", ft_strjoin("J", "ello"));
    printf("%s\n", ft_strjoin("asdasd", ":))))"));
    printf("--------- STRJOIN ---------\n\n");

    printf("--------- STRTRIM ---------\n");
    printf("%s\n", ft_strtrim("yyyyyyyyEcoleyzzzzxx", "xyz"));
    printf("%s\n", ft_strtrim("", "asd"));
    printf("%s\n", ft_strtrim("Hola", "Ha"));
    printf("%s\n", ft_strtrim("Empty set", ""));
    printf("--------- STRTRIM ---------\n\n");

    printf("--------- FT_SPLIT ---------\n");
    char **res1 = ft_split("      split       this for   me  !       ", ' ');
    for (int i = 0; res1[i]; i++) printf("%s\n", res1[i]);
    printf("\n");
    char **res2 = ft_split("   Hola", ' ');
    for (int i = 0; res2[i]; i++) printf("%s\n", res2[i]);
    printf("\n");
    char **res3 = ft_split("     Hola   que  talco  ", ' ');
    for (int i = 0; res3[i]; i++) printf("%s\n", res3[i]);
    printf("\n");
    char **res4 = ft_split("Empty set", ' ');
    for (int i = 0; res4[i]; i++) printf("%s\n", res4[i]);
    printf("--------- FT_SPLIT ---------\n\n");

    printf("--------- FT_ITOA ---------\n");
    printf("%s\n", ft_itoa(12));
    printf("%s\n", ft_itoa(-12312));
    printf("%s\n", ft_itoa(-2147483647 -1));
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-42));
    printf("%s\n", ft_itoa(0));
    printf("--------- FT_ITOA ---------\n\n");

    printf("--------- FT_STRMAPI ---------\n");
    printf("%s\n", ft_strmapi("hola", strmapitest));
    printf("%s\n", ft_strmapi("hola", toupermapi));
    printf("--------- FT_STRMAPI ---------\n\n");

    printf("--------- FT_STRITERI ---------\n");
    char    stit1[9] = "Ecole 42";
    char    stit2[10] = "Scuola 42";
    ft_striteri(stit1, iteritest1);
    ft_striteri(stit2, iteritest2);
    printf("%s\n", stit1);
    printf("%s\n", stit2);
    printf("--------- FT_STRITERI ---------\n\n");

    printf("-------------------- BONUS -------------------\n");
    printf("-------------------- BONUS -------------------\n");

    return (0);
}

char    strmapitest(unsigned int i, char c)
{
    return (c + i);
}

char    toupermapi(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void    iteritest1(unsigned int i, char* s)
{
    (void)i;
    *s -= 32;
}

void    iteritest2(unsigned int i, char* s)
{
    (void)i;
    *s = 'a';
}

