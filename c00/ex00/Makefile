NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = ./megaphone.cpp

all: $(NAME)

$(NAME): $(FILE)
	$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean clean

.PHONEY: all clean fclean re