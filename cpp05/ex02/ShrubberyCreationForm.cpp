#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) 
	: AForm(src.getName(), src.getGradeSign(), src.getGradeExecute()), _target(src._target)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->setSigned(rhs.getSigned()); 
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkExecuteForm(executor);
	std::string filename = _target + "_shrubbery";
	std::ofstream ofs(filename.c_str());

	if (ofs)
	{
		int layer = 7;
		int foliage = 1;

		for (int i = 0; i < layer; i++, foliage += 2)
		{
			for (int j = 0; j < layer - i - 1; j++)
				ofs << " ";
			for (int k = 0; k < foliage; k++)
				ofs << "*";
			ofs << std::endl;
		}
		for (int i = 0; i < (foliage - 3) / 2; i++)
			ofs << " ";
		ofs << "|" << std::endl;
	}
	else
		std::cout << "Invalid ofstream" << std::endl;

	ofs.close();
}
