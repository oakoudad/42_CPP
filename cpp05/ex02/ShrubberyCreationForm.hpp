#pragma once

#include <iostream>
#include <fstream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class Bureaucrat;

class	ShrubberyCreationForm: public AForm {
	private :
		const std::string	name;
		bool				sign;
		const int			requeredSignGrade;
		const int			requeredExecGrade;


	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &obj );
		ShrubberyCreationForm( const std::string name);
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &rhs);

		std::string const	&getName() const;
		bool				getSign() const;
		int					getRequeredSignGrade() const;
		int					getRequeredExecGrade() const;
		void				beSigned(Bureaucrat const &B);
		
		void		        execute(Bureaucrat const &B) const;
		
		virtual ~ShrubberyCreationForm();
		
		class GradeTooHighException : public  std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &COUT, ShrubberyCreationForm const & rhs);