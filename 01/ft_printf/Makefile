CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = ./includes ./libft

# Source files (wildcard expands all .c in srcs)
SRCS = $(wildcard ./srcs/*.c)
# Object files: replace .c with .o for all SRCS + ft_printf.o
OFILES = $(SRCS:.c=.o) ft_printf.o

NAME = libftprintf.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build printf lib from libft + objs
$(NAME): $(LIBFT) $(OFILES)
	cp $(LIBFT) $(NAME)           # start from libft.a
	ar rcs $(NAME) $(OFILES)      # add printf objects

# Compile .c to .o, addprefix prepends -I to each include dir
%.o: %.c
	cc $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

clean:
	rm -rf $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all bonus
