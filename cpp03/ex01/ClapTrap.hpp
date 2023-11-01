#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {

	protected:

		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;


	public:

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		ClapTrap &	operator=( ClapTrap const & rhs );
		~ClapTrap( void );

		std::string	getName( void ) const;
		int			getHitPoint( void ) const;
		int			getEnergyPoint( void ) const;
		int			getAttackDamage( void ) const;
		
		void	setName( std::string name );
		void	setHitPoint( int hitPoint );
		void	setEnergyPoint( int energyPoint );
		void	setAttackDamage( int attackDamage );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

};

#endif
