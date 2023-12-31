#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm::Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm::Grade too low";
}

const char *AForm::UnsignedException::what() const throw()
{
	return "AForm::Form not yet signed";
}

AForm::AForm(void) : _name("Default Form"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) 
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &src) 
	: _name(src._name), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	*this = src;
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned(); 
	return *this;
}

AForm::~AForm(void)
{
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

const std::string &AForm::getName(void) const
{
	return _name;
}

const bool &AForm::getSigned(void) const
{
	return _signed;
}

const int &AForm::getGradeSign(void) const
{
	return _gradeSign;
}

const int &AForm::getGradeExecute(void) const
{
	return _gradeExecute;
}

void AForm::setSigned(const bool &sign)
{
	_signed = sign;
}

void AForm::checkExecuteForm(Bureaucrat const &executor) const
{
	if (!_signed)
		throw UnsignedException();
	else if (executor.getGrade() > _gradeExecute)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << "AForm " << src.getName() << " needs grade " << src.getGradeSign() << " to sign and grade "
	<< src.getGradeExecute() << " to execute." << std::endl;

	o << "AForm " << src.getName();

	if (src.getSigned())
		o << " is signed.";
	else
		o << " is not signed.";

	o << std::endl;

	return o; 
}
