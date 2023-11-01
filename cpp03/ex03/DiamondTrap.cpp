#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) {
	_name = "Default";
	_hitPoint = FragTrap::_fragHitPoint;
	_energyPoint = ScavTrap::_scavEnergyPoint;
	_attackDamage = FragTrap::_fragAttackDamage;
	std::cout << "Default Constructor of DiamondTrap is called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name) , FragTrap(name) {
	_name = name;
	_hitPoint = FragTrap::_fragHitPoint;
	_energyPoint = ScavTrap::_scavEnergyPoint;
	_attackDamage = FragTrap::_fragAttackDamage;
	std::cout << "Parameterized constructor of DiamondTrap is called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) {
	std::cout << "Copy constructor of DiamondTrap is called" << std::endl;
	*this = src;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs ) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "Destructor of DiamondTrap is called" << std::endl;
}

std::string	DiamondTrap::getDiamondTrapName( void ) const {
	return _name;
}

int	DiamondTrap::getDiamondTrapHitPoint( void ) const {
	return _hitPoint;
}

int DiamondTrap::getDiamondTrapEnergyPoint( void ) const {
	return _energyPoint;
}

int	DiamondTrap::getDiamondTrapAttackDamage( void ) const {
	return _attackDamage;
}

void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "I am " << _name << std::endl;
	std::cout << "Clap Trap is " << ClapTrap::_name << std::endl;
}
