#ifndef		FORM_HPP
# define	FORM_HPP

#include <iostream>

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

#endif