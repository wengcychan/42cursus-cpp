#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::Grade too low";
}

Form::Form(std::string name, int gradeSign, int gradeExecute) 
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src) 
	: _name(src._name), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	*this = src;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned(); 
	return *this;
}

Form::~Form(void)
{
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

const std::string &Form::getName(void) const
{
	return _name;
}

const bool &Form::getSigned(void) const
{
	return _signed;
}

const int &Form::getGradeSign(void) const
{
	return _gradeSign;
}

const int &Form::getGradeExecute(void) const
{
	return _gradeExecute;
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form " << src.getName() << " needs grade " << src.getGradeSign() << " to sign and grade "
	<< src.getGradeExecute() << " to execute." << std::endl;

	o << "Form " << src.getName();

	if (src.getSigned())
		o << " is signed.";
	else
		o << " is not signed.";

	o << std::endl;

	return o; 
}
