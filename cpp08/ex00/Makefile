RED    = \033[0;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
RESET  = \033[0m

NAME = easyfind

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ Project $(NAME) created.$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)✓ Project $(NAME) and all files cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re