CFLAGS = -Wall -Wextra -Werror

# Wildcard grabs all .c files, in this case in the folder /srcs
SRCS = $(wildcard srcs/*.c)

# Convert the list of %.c generated with SRCS to %.o
OBJ = $(SRCS:%.c=%.o)

# Same logic, but for bonus files
CBONUS = $(wildcard bonus/*.c)
OBONUS = $(CBONUS:%.c=%.o)

INCLUDE = ./include

NAME = libft.a

all: $(NAME)

# Build the static library 
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Take all the .c files and compile the .o files needed foor creating the lib
srcs/%.o : srcs/%.c
	cc $(CFLAGS) -I $(INCLUDE) -c $< -o $@

# Add bonus files to the lib
extra: all $(OBONUS)
	ar rcs $(NAME) $(OBONUS)

bonus/%.o : bonus/%.c
	cc $(CFLAGS) -I $(INCLUDE) -c $< -o $@

# Remove the object files
clean:
	rm -rf $(OBJ) $(OBONUS)

# Run clean and then remove the library as well
fclean: clean
	rm -rf $(NAME)

# Run fclean and then Re-build the library
re: fclean all

# Clarify with phony that this are commands and not files
.PHONY: clean fclean re all extra