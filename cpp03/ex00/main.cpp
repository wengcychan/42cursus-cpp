#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {

	{
		std::cout << std::endl;

		ClapTrap claptrap1("claptrap1");

		claptrap1.attack("claptrap2");
		claptrap1.takeDamage(1);
		claptrap1.beRepaired(2);
	}

	std::cout << "-------------------" << std::endl;
	
	//can’t do anything if it has no hit points left
	{
		std::cout << std::endl;

		ClapTrap claptrap3("claptrap3");
		claptrap3.setAttackDamage(10);

		claptrap3.attack("claptrap4");
		claptrap3.takeDamage(9);
		claptrap3.takeDamage(1);
		claptrap3.beRepaired(1);
		claptrap3.takeDamage(1);
		claptrap3.attack("claptrap4");
	}

	std::cout << "-------------------" << std::endl;

	//can’t do anything if it has no hit points left
	{
		std::cout << std::endl;

		ClapTrap claptrap5("claptrap5");

		claptrap5.takeDamage(11);
		claptrap5.takeDamage(1);
		claptrap5.beRepaired(1);
		claptrap5.takeDamage(1);
		claptrap5.attack("claptrap6");
	}

	std::cout << "-------------------" << std::endl;

	//cost 1 energy point for attacking and can’t do anything if it has no energy points left
	{
		std::cout << std::endl;

		ClapTrap claptrap7("claptrap7");
		claptrap7.setAttackDamage(5);

		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.attack("claptrap8");
		claptrap7.beRepaired(1);
		claptrap7.takeDamage(1);
	}

	std::cout << "-------------------" << std::endl;

	//cost 1 energy point for repairing and can’t do anything if it has no energy points left
	{
		std::cout << std::endl;

		ClapTrap claptrap9("claptrap9");

		claptrap9.beRepaired(1);
		claptrap9.beRepaired(2);
		claptrap9.beRepaired(3);
		claptrap9.beRepaired(4);
		claptrap9.beRepaired(5);
		claptrap9.beRepaired(6);
		claptrap9.beRepaired(7);
		claptrap9.beRepaired(8);
		claptrap9.beRepaired(9);
		claptrap9.beRepaired(10);
		claptrap9.attack("claptrap10");
		claptrap9.beRepaired(1);
		claptrap9.takeDamage(10);
	}

	std::cout << "-------------------" << std::endl;
	
	return 0;
}
