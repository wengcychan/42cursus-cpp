#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	//ex00
	{
		// AAnimal meta;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();

		delete i;
		delete j;
	}

	std::cout << "----------------------" << std::endl;

	//ex01
	{
		// with array of Animals, half of it is dogs and half of it is cats
		{
			const int	nbAnimal = 4;

			AAnimal* animals[nbAnimal];

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
	}

	return 0;
}
