#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {

	private:

		AForm *createShrubberyCreationForm(std::string &target);
		AForm *createPresidentialPardonForm(std::string &target);
		AForm *createRobotomyRequestForm(std::string &target);		

	public:

		Intern(void);
		Intern(Intern const &src);
		Intern &operator=(Intern const &rhs);
		~Intern(void);

		AForm *makeForm(std::string name, std::string target);

};

#endif