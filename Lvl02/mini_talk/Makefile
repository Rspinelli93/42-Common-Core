CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCLUDES = ./includes

# Shared sources
COMMON_SRCS = $(wildcard ./srcs/*.c) \
              $(wildcard ./libft/*.c) \
              $(wildcard ./ft_printf/*.c) \
              $(wildcard ./ft_printf/srcs/*.c)

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

# Programs
CLIENT = client
SERVER = server

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

# ---- Executables ----
$(CLIENT): $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# ---- Compile rule ----
%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(COMMON_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
