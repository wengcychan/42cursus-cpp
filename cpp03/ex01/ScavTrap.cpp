#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Default Constructor of ScavTrap is called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Parameterized constructor of ScavTrap is called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {
	std::cout << "Copy constructor of ScavTrap is called" << std::endl;
	*this = src;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs ) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "Destructor of ScavTrap is called" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {

	if (ClapTrap::getHitPoint() == 0) {
		std::cout << "Scav Trap " << getName() << " cannot attack because it is already dead" << std::endl;
		return;
	}
	if (ClapTrap::getEnergyPoint() == 0) {
		std::cout << "Scav Trap " << getName() << " has no energy point for attacking" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "Scav Trap " << getName() << " attacks " << target;
	std::cout << ", causing " << getAttackDamage() << " points of damage" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	if (ClapTrap::getHitPoint() == 0)
		std::cout << "Scav Trap " << getName() << " cannot enter Gate keeper mode because it is already dead" << std::endl;
	else
		std::cout << "Scav Trap " << getName() << " is now in Gate keeper mode" << std::endl;
}
