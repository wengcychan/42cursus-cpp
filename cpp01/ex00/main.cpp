#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie	*newZombie( std::string name );

int main ( void ) {

	Zombie *zombiePtr = newZombie("Foo");
	zombiePtr->announce();
	delete zombiePtr;

	randomChump("Bar");

	return 0;

}
