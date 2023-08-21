#include "./Form.hpp"

Form::Form():name(""), sign(false), requeredSignGrade(150), requeredExecGrade(150)
{}

Form::Form( const Form &obj ):name(obj.name), requeredSignGrade(obj.requeredSignGrade), requeredExecGrade(obj.requeredExecGrade)
{
	this->sign = obj.sign;
}

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
	COUT << " is ";
	return COUT;
}

Form::~Form(){}