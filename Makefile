NAME = WebServ
CC = c++
RM = rm -f
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g3 -fsanitize=address

SRCS = main.cpp Server.cpp Configuration.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@clear
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean