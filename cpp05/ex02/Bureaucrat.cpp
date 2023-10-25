#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Bureaucrat"), grade(75){}

Bureaucrat::Bureaucrat( const Bureaucrat &obj )
{
	this->grade = obj.grade;
}

Bureaucrat::Bureaucrat( const std::string name, const unsigned int grade ):name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat &rhs)
{
	if (&rhs != this)
		this->grade = rhs.grade;
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

void	Bureaucrat::increment()
{
	if (this->grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->grade--;
}

void	Bureaucrat::decrement()
{
	if (this->grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->grade++;
}

void 	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &COUT, Bureaucrat const &rhs)
{
	COUT << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return COUT;
}

Bureaucrat::~Bureaucrat(){}