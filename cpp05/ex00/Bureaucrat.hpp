#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

#include	<iostream>

class	Bureaucrat {
	protected :
		const std::string	name;
		int					grade;

	public :
		Bureaucrat();
		Bureaucrat( const Bureaucrat &obj );
		Bureaucrat( const std::string name, const unsigned int grade );
		Bureaucrat &operator =(const Bureaucrat &rhs);
		
		std::string		getName() const;
		int				getGrade() const;

		void			increment();
		void			decrement();

		çç;
};

// std::ostream& operator<<(std::ostream &COUT, Bureaucrat const & rhs);

#endif