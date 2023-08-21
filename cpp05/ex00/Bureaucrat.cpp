#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name(""), grade(1)
{
	std::cout << "Param constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &obj )
{
	this->grade = obj.grade;
	std::cout << "Param constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, const unsigned int grade ):name(name), grade(grade)
{}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat &rhs)
{
	if (&rhs != this)
		this->grade = rhs.grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::increment()
{
	if (this->grade - 1 < 1)
	{
		// Exeption here
		std::cout << "IT'S Zero" << std::endl;
		return ;
	}
	this->grade--;
}

void	Bureaucrat::decrement()
{
	if (this->grade + 1 > 150)
	{
		// Exeption here
		std::cout << "UP THEN 150" << std::endl;
		return ;
	}
	this->grade++;
}

Bureaucrat::~Bureaucrat()
{
	
}