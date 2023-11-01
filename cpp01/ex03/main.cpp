#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	//HumanA - change weapon
	{
		std::cout << "----------------------" << std::endl;

		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	//HumanB - change weapon
	{
		std::cout << "----------------------" << std::endl;

		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	//HumanB - without weapon
	{
		std::cout << "----------------------" << std::endl;

		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	//HumanB - without weapon and arm with weapon later on
	{
		std::cout << "----------------------" << std::endl;

		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		club.setType("some other type of club");
		jim.setWeapon(club);
		jim.attack();
	}

	//HumanA - empty weapon and set weapon type
	{
		std::cout << "----------------------" << std::endl;

		Weapon club = Weapon("");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	//HumanB - empty weapon and set weapon type
	{
		std::cout << "----------------------" << std::endl;

		Weapon club = Weapon();

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;

}
