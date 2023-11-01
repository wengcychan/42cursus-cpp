#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void	HumanB::attack( void ) { 
	
	if (!_weapon || !_weapon->getType().length())
		std::cout << _name << " doesn't have weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;

}

void	HumanB::setWeapon( Weapon &weapon ) { _weapon = &weapon; }
