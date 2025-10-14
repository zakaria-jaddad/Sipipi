NAME = megaphone
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CXX) $(CFLAGS) -c $< -o  $@ -MMD

re: fclean all

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY: clean
