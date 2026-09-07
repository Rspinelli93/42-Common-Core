#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "../get_next_line.h"

char *files[15] = {
	"files/test_alternate_multiple_new_line",		//0
	"files/test_consecutive_lines",					//1
	"files/test_one_char",							//2
	"files/test_empty",								//3
	"files/test_empty_newline",						//4
	"files/test_ends_with_newline",					//5
	"files/test_long_alternate_multiple_new_line",	//6
	"files/test_long_ends_with_newline",			//7
	"files/test_long_line",							//8
	"files/test_long_multiple_newline",				//9
	"files/test_multiple_newline",					//10
	"files/test_no_newline",						//11
	"files/test_only_newline",						//12
	"files/test_same_line_length",					//13
	"files/invaid"									//14
};

int	main()
{
	char	*line;

	for (int j = 0; j < 15; j++)
	{
		char	*file = files[j];

		int fd = open(file, O_RDONLY);

		// printf("file: %s, fd: %d\n\n", files[0], fd);

		for (int i = 0; i < 30; i++)
		{
			line = get_next_line(fd);
			printf("%s", line);
			free(line);
			line = NULL;
		}

		close(fd);
	}

	// while((line = get_next_line(0)))
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }

	return (0);
}
