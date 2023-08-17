NAME = PmergeMe

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
FILE = main.cpp PmergeMe.cpp

OBJ = $(FILE:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean clean all

.PHONEY: all clean fclean re