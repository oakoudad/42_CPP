#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class Bureaucrat;

class	RobotomyRequestForm: public AForm {
	private:
		std::string	target;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &obj );
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm &operator =(const RobotomyRequestForm &rhs);

		std::string const	&getTarget() const;
		void				beSigned(Bureaucrat const &B);
		
		void		        execute(Bureaucrat const &B) const;

		void print(std::ostream& os) const override {
			os << "RobotomyRequestForm output";
		}
		
		virtual ~RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream &COUT, RobotomyRequestForm const & rhs);