#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Form;

class Bureaucrat {

	private:

		const std::string _name;
		int	_grade;
		Bureaucrat(void);


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

		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);

		const std::string &getName(void) const;
		const int &getGrade(void) const;

		void	increaseGrade(void);
		void	decreaseGrade(void);

		void signForm(Form &form) const;

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif
