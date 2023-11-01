#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	//test for fragtrap
	{
		std::cout << std::endl;

		FragTrap fragtrap1("fragtrap1");

		std::cout << std::endl;

		std::cout << "name : " << fragtrap1.getName() << std::endl;
		std::cout << "hit point : " << fragtrap1.getHitPoint() << std::endl;
		std::cout << "energy point : " << fragtrap1.getEnergyPoint() << std::endl;
		std::cout << "attack damage : " << fragtrap1.getAttackDamage() << std::endl;

		std::cout << std::endl;

		fragtrap1.attack("fragtrap2");
		fragtrap1.takeDamage(1);
		fragtrap1.beRepaired(2);
		fragtrap1.highFivesGuys();

		std::cout << std::endl;

		std::cout << "name : " << fragtrap1.getName() << std::endl;
		std::cout << "hit point : " << fragtrap1.getHitPoint() << std::endl;
		std::cout << "energy point : " << fragtrap1.getEnergyPoint() << std::endl;
		std::cout << "attack damage : " << fragtrap1.getAttackDamage() << std::endl;

		std::cout << std::endl;

		fragtrap1.takeDamage(102);
		fragtrap1.attack("fragtrap2");
		fragtrap1.beRepaired(100);
		fragtrap1.highFivesGuys();

		std::cout << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	//test for diamond trap
	{
		std::cout << std::endl;

		DiamondTrap diamondtrap1("diamondtrap1");

		std::cout << std::endl;

		std::cout << "name : " << diamondtrap1.getDiamondTrapName() << std::endl;
		std::cout << "hit point : " << diamondtrap1.getDiamondTrapHitPoint() << std::endl;
		std::cout << "energy point : " << diamondtrap1.getDiamondTrapEnergyPoint() << std::endl;
		std::cout << "attack damage : " << diamondtrap1.getDiamondTrapAttackDamage() << std::endl;

		std::cout << std::endl;	

		diamondtrap1.attack("diamondtrap2");
		diamondtrap1.whoAmI();
		diamondtrap1.takeDamage(1);
		diamondtrap1.beRepaired(2);
		diamondtrap1.guardGate();
		diamondtrap1.highFivesGuys();

		std::cout << std::endl;

		std::cout << "name : " << diamondtrap1.getDiamondTrapName() << std::endl;
		std::cout << "hit point : " << diamondtrap1.getDiamondTrapHitPoint() << std::endl;
		std::cout << "energy point : " << diamondtrap1.getDiamondTrapEnergyPoint() << std::endl;
		std::cout << "attack damage : " << diamondtrap1.getDiamondTrapAttackDamage() << std::endl;

		std::cout << std::endl;

		diamondtrap1.takeDamage(102);
		diamondtrap1.attack("fragtrap2");
		diamondtrap1.beRepaired(100);
		diamondtrap1.highFivesGuys();

		std::cout << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	return 0;
}
