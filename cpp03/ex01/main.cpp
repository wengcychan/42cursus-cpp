#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	//test for claptrap
	{
		std::cout << std::endl;

		ClapTrap claptrap1("claptrap1");

		claptrap1.attack("claptrap2");
		claptrap1.takeDamage(1);
		claptrap1.beRepaired(2);
	}

	std::cout << "-------------------" << std::endl;

	//test for scavtrap
	{
		std::cout << std::endl;

		ScavTrap scavtrap1("scavtrap1");

		std::cout << std::endl;

		std::cout << "name : " << scavtrap1.getName() << std::endl;
		std::cout << "hit point : " << scavtrap1.getHitPoint() << std::endl;
		std::cout << "energy point : " << scavtrap1.getEnergyPoint() << std::endl;
		std::cout << "attack damage : " << scavtrap1.getAttackDamage() << std::endl;

		std::cout << std::endl;

		scavtrap1.attack("scavtrap2");
		scavtrap1.takeDamage(1);
		scavtrap1.beRepaired(2);
		scavtrap1.guardGate();

		std::cout << std::endl;

		std::cout << "name : " << scavtrap1.getName() << std::endl;
		std::cout << "hit point : " << scavtrap1.getHitPoint() << std::endl;
		std::cout << "energy point : " << scavtrap1.getEnergyPoint() << std::endl;
		std::cout << "attack damage : " << scavtrap1.getAttackDamage() << std::endl;

		std::cout << std::endl;

		scavtrap1.takeDamage(102);
		scavtrap1.attack("scavtrap2");
		scavtrap1.beRepaired(100);
		scavtrap1.guardGate();

		std::cout << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	return 0;
}
