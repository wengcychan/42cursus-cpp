#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <unordered_map>
#include <stdexcept>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

#define DATABASE_HEADER "date,exchange_rate"
#define INPUT_HEADER "date | value"
#define DATABASE_REGEX R"(^(\d{4}-\d{2}-\d{2}),([-+]?\d+|[-+]?\d+\.\d+)$)"
#define INPUT_REGEX R"(^(\d{4}-\d{2}-\d{2}) \| ([-+]?\d+|[-+]?\d+\.\d+)$)"

class BitcoinExchange {

	private:

		std::unordered_map<std::string, double> _databaseValue;

		void checkFile(std::string const &filename, std::ifstream &ifs) const;
		void readFile(std::ifstream &ifs, std::string const &file);
		void readColumn(std::string &line, std::string const &file, std::string const &date, std::string const &number);
		bool isValidDate(int const &year, int const &month, int const &day) const;
		void calculateBitcoinValue(double const &inputValue, std::tm const &date);

	public:

		class OpenFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		void loadDatabase(std::string const &filename);
		void checkBitcoinValue(std::string const &filename);
};

#endif