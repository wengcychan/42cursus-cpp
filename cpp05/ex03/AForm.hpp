#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:

		const std::string 	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;


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

		class UnsignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(AForm const &src);
		AForm &operator=(AForm const &rhs);
		virtual ~AForm(void);

		const std::string &getName(void) const;
		const bool &getSigned(void) const;
		const int &getGradeSign(void) const;
		const int &getGradeExecute(void) const;

		void setSigned(const bool &sign);

		void beSigned(Bureaucrat const &bureaucrat);
		void checkExecuteForm(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif