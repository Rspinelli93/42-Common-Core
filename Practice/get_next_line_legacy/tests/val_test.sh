#!/bin/bash
cc -ggdb -Wall -Wextra -Werror ../get_next_line.c ../get_next_line_utils.c test.c \
&& valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out