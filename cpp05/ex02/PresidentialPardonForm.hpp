#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class Bureaucrat;

class	PresidentialPardonForm: public AForm {
	private :
		const std::string	name;
		bool				sign;
		const int			requeredSignGrade;
		const int			requeredExecGrade;


	public :
		PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &obj );
		PresidentialPardonForm( const std::string name);
		PresidentialPardonForm &operator =(const PresidentialPardonForm &rhs);

		std::string const	&getName() const;
		bool				getSign() const;
		int					getRequeredSignGrade() const;
		int					getRequeredExecGrade() const;
		void				beSigned(Bureaucrat const &B);
		
		void		        execute(Bureaucrat const &B) const;
		
		virtual ~PresidentialPardonForm();
		
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

std::ostream& operator<<(std::ostream &COUT, PresidentialPardonForm const & rhs);