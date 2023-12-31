#include "Intern.hpp"

AForm *Intern::createShrubberyCreationForm(std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string &target)
{
	return new RobotomyRequestForm(target);
}

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int nbrFormName = 3;
	std::string formName[] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	AForm *(Intern::*createForm[])(std::string &) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

	for (int i = 0; i < nbrFormName; i++)
	{
		if (name == formName[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return  (this->*createForm[i])(target);
		}
	}
	std::cout << name << " doesn't exist" << std::endl;
	return NULL;
}
