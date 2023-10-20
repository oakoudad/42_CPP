#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():name("RobotomyRequestForm"), sign(false), requeredSignGrade(72), requeredExecGrade(45)
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &obj ):name(obj.name), requeredSignGrade(72), requeredExecGrade(45)
{
	this->sign = obj.sign;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string name ):name(name), requeredSignGrade(72), requeredExecGrade(45)
{
	if (requeredSignGrade < 1 || requeredExecGrade < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (requeredSignGrade > 150 || requeredExecGrade > 150)
		throw RobotomyRequestForm::GradeTooLowException();
	this->sign = false;
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &rhs)
{
	if (&rhs != this)
		this->sign = rhs.sign;
	return (*this);
}

std::string const	&RobotomyRequestForm::getName() const
{
	return (this->name);
}

bool				RobotomyRequestForm::getSign() const
{
	return (this->sign);
}

int					RobotomyRequestForm::getRequeredSignGrade() const
{
	return (this->requeredSignGrade);
}

int					RobotomyRequestForm::getRequeredExecGrade() const
{
	return (this->requeredSignGrade);
}

void				RobotomyRequestForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->requeredSignGrade)
		throw RobotomyRequestForm::GradeTooLowException();
	this->sign = true;
}

void		        RobotomyRequestForm::execute(Bureaucrat const &B) const
{
    srand(time(0));
    if (B.getGrade() > this->requeredExecGrade)
        throw RobotomyRequestForm::GradeTooLowException();
	if (rand() % 2)
		std::cout << B.getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << B.getName() << " has been robotomized unsuccessfully" << std::endl;
            
}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}

const char *RobotomyRequestForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

std::ostream& operator<<(std::ostream &COUT, RobotomyRequestForm const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

RobotomyRequestForm::~RobotomyRequestForm(){}