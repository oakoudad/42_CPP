#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

#include <iostream>

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

#endif