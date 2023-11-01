#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	std::cout << "----------------------" << std::endl;

	//with one Dog and one Cat
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}

	std::cout << "----------------------" << std::endl;

	// with array of Animals, half of it is dogs and half of it is cats
	{
		const int	nbAnimal = 4;

		Animal* animals[nbAnimal];

		for (int i = 0; i < nbAnimal / 2; ++i)
			animals[i] = new Dog();
		
		for (int i = nbAnimal / 2 ; i < nbAnimal; ++i)
			animals[i] = new Cat();

		for (int i = 0; i < nbAnimal; i++)
			delete animals[i];
	}

	std::cout << "----------------------" << std::endl;

	// deep copy
	{
		Dog dog1;

		dog1.setBrain("hello");
		dog1.setBrain("world");

		Dog	dog2(dog1);

		dog1.setBrain("a");
		dog2.setBrain("b");

		std::cout << std::endl << "dog 1 Brain : ";
		dog1.printBrain();
	
		std::cout << std::endl << "dog 2 Brain : ";
		dog2.printBrain();
		std::cout << std::endl;
	}

	return 0;
}
