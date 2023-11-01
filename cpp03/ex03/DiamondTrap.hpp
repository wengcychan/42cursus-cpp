#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:

		std::string	_name;


	public:

		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src );
		DiamondTrap &	operator=( DiamondTrap const & rhs );
		~DiamondTrap( void );

		std::string	getDiamondTrapName( void ) const;
		int			getDiamondTrapHitPoint( void ) const;
		int			getDiamondTrapEnergyPoint( void ) const;
		int			getDiamondTrapAttackDamage( void ) const;

		void	attack( const std::string& target );
		void	whoAmI( void );

};

#endif
