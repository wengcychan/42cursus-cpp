#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Default Constructor of FragTrap is called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Parameterized constructor of FragTrap is called" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) {
	std::cout << "Copy constructor of FragTrap is called" << std::endl;
	*this = src;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "Destructor of FragTrap is called" << std::endl;
}

void	FragTrap::attack( const std::string& target ) {

	if (ClapTrap::getHitPoint() == 0) {
		std::cout << "Frag Trap " << getName() << " cannot attack because it is already dead" << std::endl;
		return;
	}
	if (ClapTrap::getEnergyPoint() == 0) {
		std::cout << "Frag Trap " << getName() << " has no energy point for attacking" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "Frag Trap " << getName() << " attacks " << target;
	std::cout << ", causing " << getAttackDamage() << " points of damage" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	if (ClapTrap::getHitPoint() == 0)
		std::cout << "Frag Trap " << getName() << " cannot request high fives because it is already dead" << std::endl;
	else
		std::cout << "Frag Trap " << getName() << " wants high fives" << std::endl;
}
