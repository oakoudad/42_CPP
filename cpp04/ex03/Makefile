NAME = Char
CPP = c++
FLAGS = -Wall -Wextra -Werror
FLAGS_CPP98 = -std=c++98
SRCS =		AMateria.cpp\
			Character.cpp\
			Cure.cpp\
			Ice.cpp\
			main.cpp

# HEADER =	AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp Ice.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(FLAGS_CPP98) $(OBJS) -o $(NAME)

%.o: %.cpp *.hpp
	$(CPP) $(FLAGS) $(FLAGS_CPP98) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re