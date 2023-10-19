#pragma once

#include <iostream>
#include "AForm.hpp"


class AForm;

class	Bureaucrat {
	protected :
		const std::string	name;
		int					grade;

	public :
		Bureaucrat();
		Bureaucrat( const Bureaucrat &obj );
		Bureaucrat( const std::string name, const unsigned int grade );
		Bureaucrat &operator =(const Bureaucrat &rhs);
		std::string const	&getName() const;
		int					getGrade() const;
		void 				signForm(AForm &form);
		~Bureaucrat();

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

		void			increment();
		void			decrement();


};

std::ostream& operator<<(std::ostream &COUT, Bureaucrat const & rhs);

