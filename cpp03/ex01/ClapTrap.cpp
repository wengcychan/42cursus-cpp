#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Default"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Default Constructor of ClapTrap is called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Parameterized constructor of ClapTrap is called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	std::cout << "Copy constructor of ClapTrap is called" << std::endl;
	*this = src;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {
	
	if (this != &rhs) {
		_name = rhs.getName();
		_hitPoint = rhs.getHitPoint();
		_energyPoint = rhs.getEnergyPoint();
		_attackDamage = rhs.getAttackDamage();
	}

	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "Destructor of ClapTrap is called" << std::endl;
}

std::string	ClapTrap::getName( void ) const {
	return _name;
}

int	ClapTrap::getHitPoint( void ) const {
	return _hitPoint;
}

int ClapTrap::getEnergyPoint( void ) const {
	return _energyPoint;
}

int	ClapTrap::getAttackDamage( void ) const {
	return _attackDamage;
}

void	ClapTrap::setName( std::string name ) {
	_name = name;
}

void	ClapTrap::setHitPoint( int hitPoint ) {
	_hitPoint = hitPoint;
}

void	ClapTrap::setEnergyPoint( int energyPoint ) {
	_energyPoint = energyPoint;
}

void	ClapTrap::setAttackDamage( int attackDamage ) {
	_attackDamage = attackDamage;
}

void	ClapTrap::attack( const std::string& target ) {
	if (_hitPoint == 0) {
		std::cout << "Clap Trap " << _name << " cannot attack because it is already dead" << std::endl;
		return;
	}
	if (_energyPoint == 0) {
		std::cout << "Clap Trap " << _name << " has no energy point for attacking" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "Clap Trap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (_hitPoint == 0)
		std::cout << "Clap Trap " << _name << " cannot be attacked because it is already dead" << std::endl;
	else if (_hitPoint <= amount) {
		std::cout << "Clap Trap " << _name << " takes damage, ";
		std::cout << "deducted " << _hitPoint << " hit point, ";
		_hitPoint = 0;
		std::cout << "with " << _hitPoint << " hit point left, ";
		std::cout << "and is now dead" << std::endl;
	}
	else {
		_hitPoint -= amount;
		std::cout << "Clap Trap " << _name << " takes damage, ";
		std::cout << "deducted " << amount << " hit point, ";
		std::cout << "with " << _hitPoint << " hit point left" << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (_hitPoint == 0) {
		std::cout << "Clap Trap " << _name << " cannot be repaired because it is already dead" << std::endl;
		return;
	}
	if (_energyPoint == 0) {
		std::cout << "Clap Trap " << _name << " has no energy point for repairing" << std::endl;
		return;
	}
	_hitPoint += amount;
	_energyPoint--;
	std::cout << "Clap Trap " << _name << " is repaired with ";
	std::cout << amount << " hit point, ";
	std::cout << "and now has " << _hitPoint << " hit point" << std::endl;
}
