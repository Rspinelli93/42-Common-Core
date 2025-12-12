CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iminilibx-linux
INCLUDES = ./includes ./libs/libft ./libs/gnl
LINUX_API = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
LFLAGS = -Iminilibx-linux -O3

# ---------------- LIBRARY ----------------
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = libs/gnl
GNL = $(GNL_DIR)/gnl.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

# ---------------- SOURCE ----------------
SRCS = \
	cubed.c \
#	srcs/exit.c \
	srcs/keyboard.c \
	srcs/flood_algo.c \
	srcs/map_parser.c \
	srcs/map.c \
	srcs/render.c \
	srcs/sprites.c \
	srcs/window.c \

# ------------- COMPILING ----------------

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: $(LIBFT) $(GNL) $(MLX) $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(GNL) $(MLX) $(LINUX_API) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) $(LFLAGS) -c $< -o $@

# ------------ CLEAN RULES --------------

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
