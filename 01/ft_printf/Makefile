CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

# Source files (wildcard expands all .c in srcs)
SRCS = $(wildcard ./srcs/*.c) $(wildcard ./libft/*.c)
# Object files: replace .c with .o for all SRCS + ft_printf.o
OFILES = $(SRCS:.c=.o) ft_printf.o

NAME = libftprintf.a

all: $(NAME)

# Build printf lib from libft + objs
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

# Compile .c to .o, addprefix prepends -I to each include dir
%.o: %.c
	cc $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
