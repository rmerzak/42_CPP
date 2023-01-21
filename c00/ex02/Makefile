NAME = Account

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILE = tests.cpp Account.cpp

OBJ = $(FILE:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean clean

.PHONEY: all clean fclean re