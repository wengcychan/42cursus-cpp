#include "BitcoinExchange.hpp"
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <regex>

const char *BitcoinExchange::OpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		_databaseValue = rhs._databaseValue;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream ifs(filename);
	checkFile(filename, ifs);
	readFile(ifs, "database");
	ifs.close();
}

void BitcoinExchange::checkBitcoinValue(std::string const &filename)
{
	std::ifstream ifs(filename);
	checkFile(filename, ifs);
	readFile(ifs, "input");
	ifs.close();
}

void BitcoinExchange::checkFile(std::string const &filename, std::ifstream &ifs) const
{
	struct stat		info;

	stat(filename.c_str(), &info);
	if (!ifs || (info.st_mode & S_IFDIR)) {
		ifs.close();
		throw OpenFileException();
	}
}

void BitcoinExchange::readFile(std::ifstream &ifs, std::string const &file)
{
	std::string expectedHeader = (file == "database") ? DATABASE_HEADER : INPUT_HEADER;
  std::string regexPattern = (file == "database") ? DATABASE_REGEX : INPUT_REGEX;

	std::string line;
	if (!getline(ifs, line) || line != expectedHeader)
	{
		std::cout << "incorrect or missing header" << std::endl;
		return;
	}

	while (getline(ifs, line))
	{
			if (line.empty())
					continue;

			std::smatch match;
			if (!std::regex_search(line, match, std::regex(regexPattern)))
			{
					std::cout << "Error: bad input => " << line << std::endl;
					continue;
			}
			readColumn(line, file, match[1], match[2]);
	}
}
	
	void BitcoinExchange::readColumn(std::string &line, std::string const &file, std::string const &date, std::string const &number)
	{
			std::tm tmDate = {};
			std::istringstream iss(date);
			iss >> std::get_time(&tmDate, "%Y-%m-%d");
			if (iss.fail() || !isValidDate(tmDate.tm_year + 1900, tmDate.tm_mon + 1, tmDate.tm_mday))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				return;
			}

			if (number.front() == '-')
			{
				std::cout << "Error: not a positive number." << std::endl;
				return;
			}

			if (file == "database")
				_databaseValue[std::to_string(tmDate.tm_year) + "-" + std::to_string(tmDate.tm_mon) + "-" + std::to_string(tmDate.tm_mday)] = std::stod(number);
			else
			{
				double inputValue = std::stod(number);
				if (inputValue == 0)
				{
					std::cout << "Error: not a positive number." << std::endl;
					return;
				}
				if (inputValue > 1000)
				{
					std::cout << "Error: too large a number." << std::endl;
					return;
				}

				calculateBitcoinValue(inputValue, tmDate);
			}
	}

bool BitcoinExchange::isValidDate(int const &year, int const &month, int const &day) const
{
  if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return day <= 29;
		else
			return day <= 28;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;

	return true;
}

void BitcoinExchange::calculateBitcoinValue(double const &inputValue, std::tm const &date)
{
	std::tm dateToFind = date;
	while (dateToFind.tm_year >= 2009 - 1900)
	{
		std::unordered_map<std::string, double>::iterator it = _databaseValue.find(std::to_string(dateToFind.tm_year) + "-" + std::to_string(dateToFind.tm_mon) + "-" + std::to_string(dateToFind.tm_mday));

		if (it != _databaseValue.end())
		{
			std::cout << std::fixed << std::setprecision(2) << date.tm_year + 1900 << "-" 
				<< std::setw(2) << std::setfill('0') << date.tm_mon + 1 << "-" 
				<< std::setw(2) << std::setfill('0') << date.tm_mday << " => " 
				<< inputValue << " = " << it->second * inputValue << std::endl;
			return;
		}
		dateToFind.tm_mday--;
		if (dateToFind.tm_mday == 0)
		{
			dateToFind.tm_mday = 31;
			dateToFind.tm_mon--;
			if (dateToFind.tm_mon == -1)
			{
				dateToFind.tm_mon = 11;
				dateToFind.tm_year--;
			}
		}
	}
	std::cout << "Error: no record in the database" << std::endl;
}
