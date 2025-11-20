NAME = main
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)

CXX = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o  $@ -MMD

re: fclean all

clean: 
	rm -rf $(OBJ) $(OBJ:.o=.d)

fclean: clean
	rm -rf $(NAME)

.PHONY: clean
-include $(OBJ:.o=.d)
