NAME = Sed

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp

OBJ = $(FILE:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	rm -rf *.o

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean clean all

.PHONEY: all clean fclean re