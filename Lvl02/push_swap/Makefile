CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

# Source files (wildcard expands all .c in srcs)
SRCS = ./push_swap.c $(wildcard ./operations/*.c) $(wildcard ./ft_printf/srcs/*.c) $(wildcard ./libft/*.c) $(wildcard ./ft_printf/*.c) $(wildcard ./srcs/*.c)
# Object files: replace .c with .o for all SRCS + ft_printf.o
OFILES = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

# Executable
$(NAME): $(OFILES)
	cc $(CFLAGS) $(OFILES) -o $(NAME)

# Compile .c to .o, addprefix prepends -I to each include dir
%.o: %.c
	cc $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
