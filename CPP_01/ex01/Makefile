NAME = zombieHord
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
INCLUDES = Zombie.hpp

#Colors and styles:
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
RESET	= \033[0m
BOLD	= \033[1m
UNDERLINE = \033[4m

SRC =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@echo -n "$(YELLOW)Compiling $(BOLD)$(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)\nDone.$(RESET)"

%.o: %.cpp $(INCLUDES) Makefile
	@echo "$(CYAN)Creating object file for $<...$(RESET)"
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@
	@echo "$(GREEN)Finished $@$(RESET)"

all : $(NAME)

clean:
	@echo -n "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ)
	@echo "$(GREEN)\nObject files cleaned.$(RESET)"

fclean: clean
	@echo -n "$(RED)Removing executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re