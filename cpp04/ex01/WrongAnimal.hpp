#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

	protected:

		std::string	_type;
	

	public:

		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal & operator=( WrongAnimal const & rhs );
		virtual	~WrongAnimal( void );

		void			makeSound( void ) const;
		std::string		getType( void ) const;

};

#endif
