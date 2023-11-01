#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	_name = "Default";
	_hitPoint = 100;
	_energyPoint = 50;
	_scavEnergyPoint = _energyPoint;
	_attackDamage = 20;
	std::cout << "Default Constructor of ScavTrap is called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	_name = name;
	_hitPoint = 100;
	_energyPoint = 50;
	_scavEnergyPoint = _energyPoint;
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

	if (ClapTrap::_hitPoint == 0) {
		std::cout << "Scav Trap " << _name << " cannot attack because it is already dead" << std::endl;
		return;
	}
	if (ClapTrap::_energyPoint == 0) {
		std::cout << "Scav Trap " << _name << " has no energy point for attacking" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "Scav Trap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	if (ClapTrap::_hitPoint == 0)
		std::cout << "Scav Trap " << _name << " cannot enter Gate keeper mode because it is already dead" << std::endl;
	else
		std::cout << "Scav Trap " << _name << " is now in Gate keeper mode" << std::endl;
}
