#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	_name = "Default";
	_hitPoint = 100;
	_fragHitPoint = _hitPoint;
	_energyPoint = 100;
	_attackDamage = 30;
	_fragAttackDamage = _attackDamage;
	std::cout << "Default Constructor of FragTrap is called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_name = name;
	_hitPoint = 100;
	_fragHitPoint = _hitPoint;
	_energyPoint = 100;
	_attackDamage = 30;
	_fragAttackDamage = _attackDamage;
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

	if (ClapTrap::_hitPoint == 0) {
		std::cout << "Frag Trap " << _name << " cannot attack because it is already dead" << std::endl;
		return;
	}
	if (ClapTrap::_energyPoint == 0) {
		std::cout << "Frag Trap " << _name << " has no energy point for attacking" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "Frag Trap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	if (ClapTrap::_hitPoint == 0)
		std::cout << "Frag Trap " << _name << " cannot request high fives because it is already dead" << std::endl;
	else
		std::cout << "Frag Trap " << _name << " wants high fives" << std::endl;
}
