#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"


class Bureaucrat;

class	Form {
	private :
		const std::string	name;
		bool				sign;
		const int			requeredSignGrade;
		const int			requeredExecGrade;


	public :
		Form();
		Form( const Form &obj );
		Form( const std::string name, const int requeredSignGrade, const int requeredExecGrade );
		Form &operator =(const Form &rhs);

		std::string const	&getName() const;
		bool				getSign() const;
		int					getRequeredSignGrade() const;
		int					getRequeredExecGrade() const;
		void				beSigned(Bureaucrat const &B);

		~Form();
		
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

std::ostream& operator<<(std::ostream &COUT, Form const & rhs);
