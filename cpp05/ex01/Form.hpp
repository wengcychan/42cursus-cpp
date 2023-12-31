#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

		const std::string 	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

		Form(void);


	public:

		class GradeTooHighException : public std::exception
		{	
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{	
			public:
				virtual const char* what() const throw();
		};

		Form(std::string name, int gradeSign, int gradeExecute);
		Form(Form const &src);
		Form &operator=(Form const &rhs);
		~Form(void);

		const std::string &getName(void) const;
		const bool &getSigned(void) const;
		const int &getGradeSign(void) const;
		const int &getGradeExecute(void) const;

		void beSigned(Bureaucrat const &bureaucrat);

};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif