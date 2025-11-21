CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iminilibx-linux
INCLUDES = ./includes ./libs/ft_printf/includes ./libs/libft
LINUX_API = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
LFLAGS = -Iminilibx-linux -O3

# ---------------- LIBRARY ----------------
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

# ---------------- SOURCE ----------------
SRCS = \
	main.c

# ------------- COMPILING ----------------

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(LIBFT) $(FT_PRINTF) $(MLX) $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(LINUX_API) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) $(LFLAGS) -c $< -o $@

# ------------ CLEAN RULES --------------

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
