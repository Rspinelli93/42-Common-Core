CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Imlx_linux
INCLUDES = ./includes /usr/include ./libs/ft_printf/includes ./libs/libft
LINUX_API = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LFLAGS = -Imlx_linux -O3

# ---------------- LIBRARY ----------------
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

#MLX_DIR = libs/minilibx-linux
#MLX = $(MLX_DIR)/libmlx.a

# ---------------- SOURCE ----------------
SRCS = \
	main.c \
#	srcs/map.c \
#	srcs/utils.c \
#	srcs/render.c \
#	srcs/player.c \
#	srcs/hooks.c \
#	srcs/images.c \
#	srcs/pathfinding.c

# ------------- COMPILING ----------------

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(LIBFT) $(FT_PRINTF) $(NAME) # $(MLX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

#$(MLX):
#	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME) #$(MLX)$(LINUX_API) 

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) $(LFLAGS) -c $< -o $@

# ------------ CLEAN RULES --------------

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
