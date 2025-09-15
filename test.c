/*
cc test.c -Wall -Wextra -Werror -L . -l ft -I include -o test

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

//* ft_isalnum
/* int main (void)
{
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
    return (0);
} */

//* ft_isalpha
/* int main (void)
{
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
    return (0);
} */

//* ft_isascii
/* int main (void)
{
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
    return (0);
} */

//* ft_isdigit
/* int main (void)
{
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
    return (0);
} */

//* ft_isprint
/* int main (void)
{
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
    return (0);
} */

//* ft_tolower
/* int main (void)
{
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
    return (0);
} */

//* ft_toupper
/* int main (void)
{
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
    return (0);
} */

//* ft_strrchr
/* int main (void)
{
    printf("%s - ", strrchr("aaabaaa", 'b'));
    printf("%s\n", ft_strrchr("aaabaaa", 'b'));
//    printf("%s - ", strrchr("aaabaaa", 'x'));
//    printf("%s\n", ft_strrchr("aaabaaa", 'x'));
    printf("%s - ", strrchr("hola", 'o'));
    printf("%s\n", ft_strrchr("hola", 'o'));
    printf("%s - ", strrchr("dogScat", 'S'));
    printf("%s\n", ft_strrchr("dogScat", 'S'));
    printf("%s - ", strrchr("[right]", '['));
    printf("%s\n", ft_strrchr("[right]", '['));
    printf("%s - ", strrchr("?42", '4'));
    printf("%s\n", ft_strrchr("?42", '4'));
    return (0);
} */

//* ft_strlen
/* int main (void)
{
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
    return (0);
} */