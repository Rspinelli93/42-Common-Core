CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes ../libft

SRCS = \
    ft_printf.c \
    srcs/ft_printhex_pf.c \
    srcs/ft_printptr_pf.c \
    srcs/ft_putchar_pf.c \
    srcs/ft_putnbr_pf.c \
    srcs/ft_putstr_pf.c \
	srcs/ft_putunsig_pf.c 

OFILES = $(SRCS:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OFILES)
	# Start with libft.a
	cp $(LIBFT) $(NAME)
	# Append ft_printf object files
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	cc $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

clean:
	rm -rf $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all
