NAME = Animal
CPP = c++
FLAGS = -Wall -Wextra -Werror
FLAGS_CPP98 = -std=c++98
SRCS =		Animal.cpp\
			Cat.cpp\
			Dog.cpp\
			WrongAnimal.cpp\
			WrongCat.cpp\
			Brain.cpp\
			main.cpp

HEADER =	Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(FLAGS_CPP98) $(OBJS) -o $(NAME)

%.o: %.cpp ${HEADER}
	$(CPP) $(FLAGS) $(FLAGS_CPP98) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re