CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iminilibx-linux
INCLUDES = ./includes ./libs/ft_printf/includes ./libs/libft ./libs/gnl
LINUX_API = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
LFLAGS = -Iminilibx-linux -O3

# ---------------- LIBRARY ----------------
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

GNL_DIR = libs/gnl
GNL = $(GNL_DIR)/gnl.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

# ---------------- SOURCE ----------------
SRCS = \
	main.c \
	srcs/exit.c \
	srcs/keyboard.c \
	srcs/logic.c \
	srcs/map_parser.c \
	srcs/map.c \
	srcs/render.c \
	srcs/sprites.c \
	srcs/window.c \

# ------------- COMPILING ----------------

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(LIBFT) $(FT_PRINTF) $(GNL) $(MLX) $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(GNL) $(FT_PRINTF) $(MLX) $(LINUX_API) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) $(LFLAGS) -c $< -o $@

# ------------ CLEAN RULES --------------

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
