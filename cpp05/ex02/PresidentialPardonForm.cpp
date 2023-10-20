#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():name("PresidentialPardonForm"), sign(false), requeredSignGrade(25), requeredExecGrade(5)
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &obj ):name(obj.name), requeredSignGrade(25), requeredExecGrade(5)
{
	this->sign = obj.sign;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string name ):name(name), requeredSignGrade(25), requeredExecGrade(5)
{
	if (requeredSignGrade < 1 || requeredExecGrade < 1)
		throw PresidentialPardonForm::GradeTooHighException();
	else if (requeredSignGrade > 150 || requeredExecGrade > 150)
		throw PresidentialPardonForm::GradeTooLowException();
	this->sign = false;
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &rhs)
{
	if (&rhs != this)
		this->sign = rhs.sign;
	return (*this);
}

std::string const	&PresidentialPardonForm::getName() const
{
	return (this->name);
}

bool				PresidentialPardonForm::getSign() const
{
	return (this->sign);
}

int					PresidentialPardonForm::getRequeredSignGrade() const
{
	return (this->requeredSignGrade);
}

int					PresidentialPardonForm::getRequeredExecGrade() const
{
	return (this->requeredSignGrade);
}

void				PresidentialPardonForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->requeredSignGrade)
		throw PresidentialPardonForm::GradeTooLowException();
	this->sign = true;
}

void		        PresidentialPardonForm::execute(Bureaucrat const &B) const
{
    srand(time(0));
    if (B.getGrade() > this->requeredExecGrade)
        throw PresidentialPardonForm::GradeTooLowException();
	std::cout << B.getName() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
            
}

const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}

const char *PresidentialPardonForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

std::ostream& operator<<(std::ostream &COUT, PresidentialPardonForm const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

PresidentialPardonForm::~PresidentialPardonForm(){}