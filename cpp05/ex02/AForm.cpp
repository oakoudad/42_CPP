#include "./AForm.hpp"

AForm::AForm():name("Form"), sign(false), requeredSignGrade(75), requeredExecGrade(75)
{}

AForm::AForm( const AForm &obj ):name(obj.name), requeredSignGrade(obj.requeredSignGrade), requeredExecGrade(obj.requeredExecGrade)
{
	this->sign = obj.sign;
}

AForm::AForm( const std::string name, const int requeredSignGrade, const int requeredExecGrade ):name(name), requeredSignGrade(requeredSignGrade), requeredExecGrade(requeredExecGrade)
{
	if (requeredSignGrade < 1 || requeredExecGrade < 1)
		throw AForm::GradeTooHighException();
	else if (requeredSignGrade > 150 || requeredExecGrade > 150)
		throw AForm::GradeTooLowException();
	this->sign = false;
}

AForm &AForm::operator =(const AForm &rhs)
{
	if (&rhs != this)
		this->sign = rhs.sign;
	return (*this);
}

void				AForm::validation(Bureaucrat const &B) const
{
	if (B.getGrade() > this->getRequeredExecGrade())
        throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw std::logic_error("is not signed");
}

std::string const	&AForm::getName() const
{
	return (this->name);
}

bool				AForm::getSign() const
{
	return (this->sign);
}

int					AForm::getRequeredSignGrade() const
{
	return (this->requeredSignGrade);
}

int					AForm::getRequeredExecGrade() const
{
	return (this->requeredExecGrade);
}

void				AForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->requeredSignGrade)
		throw AForm::GradeTooLowException();
	this->sign = true;
}




void	AForm::setSign(bool sign)
{
	this->sign = sign;
}




const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

std::ostream& operator<<(std::ostream &COUT, AForm const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

AForm::~AForm(){}