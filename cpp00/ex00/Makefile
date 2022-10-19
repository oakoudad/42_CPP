NAME = megaphone

cpp = c++

FLAGS = -Wall -Wextra -Werror
FLAGS_CPP98 = -std=c++98
SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(cpp) $(FLAGS) $(FLAGS_CPP98) $(OBJS) -o $(NAME)

megaphone.o: megaphone.cpp
	$(cpp) $(FLAGS) $(FLAGS_CPP98) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re