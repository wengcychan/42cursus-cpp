#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	protected:

		std::string		_name;
		unsigned int	_fragHitPoint;
		unsigned int	_fragAttackDamage;


	public:

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		FragTrap &	operator=( FragTrap const & rhs );
		~FragTrap( void );

		void	attack( const std::string& target );
		void	highFivesGuys( void );

};

#endif
