#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int main ( void ) {

	//allocate 10 zombies
	{
		std::cout << "----------------------" << std::endl;

		int N = 10;

		Zombie *zombieHordePtr = zombieHorde( N, "Foo");

		if (!zombieHordePtr)
			return 0;

		for (int i = 0; i < N; ++i)
			zombieHordePtr[i].announce();

		delete [] zombieHordePtr;
	}

	//allocate 1 zombie
	{
		std::cout << "----------------------" << std::endl;

		int N = 1;

		Zombie *zombieHordePtr = zombieHorde( N, "Bar");

		if (!zombieHordePtr)
			return 0;

		for (int i = 0; i < N; ++i)
			zombieHordePtr[i].announce();

		delete [] zombieHordePtr;
	}

	//allocate -10 zombies (invalid)
	{
		std::cout << "----------------------" << std::endl;
	
		int N = -10;

		Zombie *zombieHordePtr = zombieHorde( N, "Bar");

		if (!zombieHordePtr)
			return 0;

		for (int i = 0; i < N; ++i)
			zombieHordePtr[i].announce();

		delete [] zombieHordePtr;
	}

	return 0;

}
