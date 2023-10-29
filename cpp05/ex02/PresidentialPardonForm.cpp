#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("presidential pardon", 25, 5)
{
	this->target = "PPR";
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &obj ):AForm(obj.getName(), 25, 5)
{
	this->setSign(obj.getSign());
	this->target = obj.target;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ):AForm("presidential pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &rhs)
{
	if (&rhs != this)
		this->setSign(rhs.getSign());
	this->target = rhs.target;
	return (*this);
}

std::string const	&PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void				PresidentialPardonForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->getRequeredSignGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	this->setSign(true);
}

void		        PresidentialPardonForm::execute(Bureaucrat const &B) const
{
    this->validation(B);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
            
}

std::ostream& operator<<(std::ostream &COUT, PresidentialPardonForm const &rhs)
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

PresidentialPardonForm::~PresidentialPardonForm(){}