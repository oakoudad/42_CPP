#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"
#include <fstream>
#include "./AForm.hpp"

class Bureaucrat;

class	ShrubberyCreationForm: public AForm {
	private:
		std::string	target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &obj );
		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &rhs);

		std::string const	&getTarget() const;
		void				beSigned(Bureaucrat const &B);
		
		void		        execute(Bureaucrat const &B) const;
		
		virtual ~ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream &COUT, ShrubberyCreationForm const & rhs);