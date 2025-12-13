NAME = phone_book

cc = c++
CFLAGS = -Werror -Wextra -Wall -std=c++90
SRC = phone_book.cpp
OBJ = phone_book.o

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o$@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean