#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:

		Brain*	_brain;


	public:

		Dog( void );
		Dog( Dog const & src );
		Dog & operator=( Dog const & rhs );
		virtual ~Dog( void );

		virtual void	makeSound( void ) const;
		void			setBrain( std::string idea );
		void			printBrain( void );

};

#endif
