#include <iostream>
#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange btc;
		try
		{
			btc.loadDatabase("data.csv");
			btc.checkBitcoinValue(argv[1]);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: could not open file." << std::endl;

	return 0;
}