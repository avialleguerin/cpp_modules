NAME = serialize

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Serializer.cpp Data.cpp

OBJS = $(SRCS:.cpp=.o)

INCLUDES = Serializer.hpp Data.hpp

%.o: %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean re fclean

