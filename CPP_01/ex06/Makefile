.DEFAULT_GOAL = all
NAME = harlFilter
CC	=	c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC =	main.cpp \
		Harl.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
