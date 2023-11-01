#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {

	if (N < 1) {
		std::cout << "Invalid number of zombie" << std::endl;
		return NULL;
	}

	Zombie*	zombieHorde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		zombieHorde[i].setName(name);

	return zombieHorde;

}
