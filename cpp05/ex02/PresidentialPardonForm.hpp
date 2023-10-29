#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class Bureaucrat;

class	PresidentialPardonForm: public AForm {
	private:
		std::string	target;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &obj );
		PresidentialPardonForm( const std::string target );
		PresidentialPardonForm &operator =(const PresidentialPardonForm &rhs);

		std::string const	&getTarget() const;
		void				beSigned(Bureaucrat const &B);
		
		void		        execute(Bureaucrat const &B) const;
		
		virtual ~PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream &COUT, PresidentialPardonForm const & rhs);