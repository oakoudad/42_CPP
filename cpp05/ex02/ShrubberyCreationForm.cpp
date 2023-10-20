#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():name("ShrubberyCreationForm"), sign(false), requeredSignGrade(145), requeredExecGrade(137)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &obj ):name(obj.name), requeredSignGrade(145), requeredExecGrade(137)
{
	this->sign = obj.sign;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string name ):name(name), requeredSignGrade(145), requeredExecGrade(137)
{
	if (requeredSignGrade < 1 || requeredExecGrade < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (requeredSignGrade > 150 || requeredExecGrade > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	this->sign = false;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &rhs)
{
	if (&rhs != this)
		this->sign = rhs.sign;
	return (*this);
}

std::string const	&ShrubberyCreationForm::getName() const
{
	return (this->name);
}

bool				ShrubberyCreationForm::getSign() const
{
	return (this->sign);
}

int					ShrubberyCreationForm::getRequeredSignGrade() const
{
	return (this->requeredSignGrade);
}

int					ShrubberyCreationForm::getRequeredExecGrade() const
{
	return (this->requeredSignGrade);
}

void				ShrubberyCreationForm::beSigned(Bureaucrat const &B)
{
	if (B.getGrade() > this->requeredSignGrade)
		throw ShrubberyCreationForm::GradeTooLowException();
	this->sign = true;
}

void		        ShrubberyCreationForm::execute(Bureaucrat const &B) const
{
    if (B.getGrade() > this->requeredSignGrade && B.getGrade() > this->requeredExecGrade)
        throw ShrubberyCreationForm::GradeTooLowException();
    std::ofstream outfile(B.getName());
	outfile << std::string("  **   ****   ****  ******") << std::endl;
	outfile << std::string(" ***  */// * */// *//////*") << std::endl;
	outfile << std::string("//** /    /*/    /*     /*") << std::endl;
	outfile << std::string(" /**    ***    ***      * ") << std::endl;
	outfile << std::string(" /**   /// *  /// *    *  ") << std::endl;
	outfile << std::string(" /**      /*     /*   *   ") << std::endl;
	outfile << std::string(" ****/ **** / ****   *    ") << std::endl;
	outfile << std::string("////  ////   ////   /     ") << std::endl;
	outfile.close();
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

std::ostream& operator<<(std::ostream &COUT, ShrubberyCreationForm const &rhs)
{
	COUT << "_________________ FORM INFO _________________" << std::endl;
	COUT << "Name: " << rhs.getName() << std::endl;
	COUT << "Sign: " << (rhs.getSign() == 1 ? "True" : "False") << std::endl;
	COUT << "Requered Sign Grade: " << rhs.getRequeredSignGrade() << std::endl;
	COUT << "Requered Exec Grade: " << rhs.getRequeredExecGrade() << std::endl;
	COUT << "_____________________________________________" << std::endl;
	return COUT;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}