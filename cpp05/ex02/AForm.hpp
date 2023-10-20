#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"


class Bureaucrat;

class	AForm {
	private :
		const std::string	name;
		bool				sign;
		const int			requeredSignGrade;
		const int			requeredExecGrade;


	public :
		AForm();
		AForm( const AForm &obj );
		AForm( const std::string name, const int requeredSignGrade, const int requeredExecGrade );
		AForm &operator =(const AForm &rhs);

		std::string const	&getName() const;
		bool				getSign() const;
		int					getRequeredSignGrade() const;
		int					getRequeredExecGrade() const;
		void				beSigned(Bureaucrat const &B);
		
		virtual void		execute(Bureaucrat const &B) const = 0;
		
		virtual ~AForm();
		
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

std::ostream& operator<<(std::ostream &COUT, AForm const & rhs);