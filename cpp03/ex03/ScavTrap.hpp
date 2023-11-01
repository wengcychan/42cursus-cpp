#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	protected:

		std::string		_name;
		unsigned int	_scavEnergyPoint;


	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		ScavTrap &	operator=( ScavTrap const & rhs );
		~ScavTrap( void );

		void	attack( const std::string& target );
		void	guardGate( void );

};

#endif
