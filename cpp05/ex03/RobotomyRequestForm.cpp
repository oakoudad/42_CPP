#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("robotomy request", 72, 45)
{
	this->target = "RRF";
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &obj ):AForm(obj.getName(), 72, 45)
{
	this->setSign(obj.getSign());
	this->target = obj.target;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ):AForm("robotomy request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &rhs)
{
	if (&rhs != this)
		this->setSign(rhs.getSign());
	this->target = rhs.target;
	return (*this);
}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void				RobotomyRequestForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->getRequeredSignGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	this->setSign(true);
}

void		        RobotomyRequestForm::execute(Bureaucrat const &B) const
{
    srand(time(0));
    this->validation(B);
	if (rand() % 2)
		std::cout << B.getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << B.getName() << " has been robotomized unsuccessfully" << std::endl;
            
}

std::ostream& operator<<(std::ostream &COUT, RobotomyRequestForm const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Target: " << rhs.getTarget() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

RobotomyRequestForm::~RobotomyRequestForm(){}