#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int	Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;

}

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0) {

	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "created" << std::endl;

}

Account::~Account( void ) {

	_nbAccounts--;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "closed" << std::endl;

}

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";

	if (checkAmount() < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;

}

int		Account::checkAmount( void ) const { return _amount; }

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;

}

void	Account::_displayTimestamp( void ) {

	time_t		current_time;
	char		buf[16];

	std::time(&current_time);
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", std::localtime(&current_time));
	std::cout << "[" << buf << "] ";
	// std::cout << "[19920104_091532] ";

}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
