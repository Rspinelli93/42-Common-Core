CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Imlx_linux
INCLUDES = ./includes /usr/include
LINUX_API = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LFLAGS = -Imlx_linux -O3
# Shared sources
SRCS = $(wildcard ./srcs/*.c) \
              $(wildcard ./libft/*.c) \
              $(wildcard ./ft_printf/*.c) \
              $(wildcard ./ft_printf/srcs/*.c)

OBJS = $(SRCS:.c=.o)

# Programs
NAME = so_long

all: $(NAME)

# ---- Executable ----
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LINUX_API) $^ -o $@

# ---- Compile rule ----
%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) $(LFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
