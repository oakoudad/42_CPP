NAME = Form
CPP = c++
FLAGS = -Wall -Wextra -Werror
FLAGS_CPP98 = -std=c++98
SRCS =  Bureaucrat.cpp\
        AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp\
		Intern.cpp\
		main.cpp

HEADER = AForm.hpp Bureaucrat.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

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