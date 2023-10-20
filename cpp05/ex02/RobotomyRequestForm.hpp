#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class Bureaucrat;

class	RobotomyRequestForm: public AForm {
	private :
		const std::string	name;
		bool				sign;
		const int			requeredSignGrade;
		const int			requeredExecGrade;


	public :
		RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &obj );
		RobotomyRequestForm( const std::string name);
		RobotomyRequestForm &operator =(const RobotomyRequestForm &rhs);

		std::string const	&getName() const;
		bool				getSign() const;
		int					getRequeredSignGrade() const;
		int					getRequeredExecGrade() const;
		void				beSigned(Bureaucrat const &B);
		
		void		        execute(Bureaucrat const &B) const;
		
		virtual ~RobotomyRequestForm();
		
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

std::ostream& operator<<(std::ostream &COUT, RobotomyRequestForm const & rhs);