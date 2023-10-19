#include "./Form.hpp"

Form::Form():name("Form"), sign(false), requeredSignGrade(75), requeredExecGrade(75)
{}

Form::Form( const Form &obj ):name(obj.name), sign(obj.sign), requeredSignGrade(obj.requeredSignGrade), requeredExecGrade(obj.requeredExecGrade)
{}

Form::Form( const std::string name, const int requeredSignGrade, const int requeredExecGrade ):name(name), requeredSignGrade(requeredSignGrade), requeredExecGrade(requeredExecGrade)
{
	if (requeredSignGrade < 1 || requeredExecGrade < 1)
		throw Form::GradeTooHighException();
	else if (requeredSignGrade > 150 || requeredExecGrade > 150)
		throw Form::GradeTooLowException();
	this->sign = false;
}

Form &Form::operator =(const Form &rhs)
{
	if (&rhs != this)
		this->sign = rhs.sign;
	return (*this);
}

std::string const	&Form::getName() const
{
	return (this->name);
}

bool				Form::getSign() const
{
	return (this->sign);
}

int					Form::getRequeredSignGrade() const
{
	return (this->requeredSignGrade);
}

int					Form::getRequeredExecGrade() const
{
	return (this->requeredSignGrade);
}

void				Form::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->requeredSignGrade)
		throw Form::GradeTooLowException();
	this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}



std::ostream& operator<<(std::ostream &COUT, Form const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

Form::~Form(){}