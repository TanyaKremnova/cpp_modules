#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	// timestamp in format [YYYYMMDD_HHMMSS]
	// [19920104_091532] 
	std::time_t	now = std::time(NULL);
	std::tm		*lt = std::localtime(&now);

	std::cout	<< '['
				<< (lt->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << lt->tm_mon + 1
				<< std::setw(2) << lt->tm_mday
				<< '_'
				<< std::setw(2) << lt->tm_hour
				<< std::setw(2) << lt->tm_min
				<< std::setw(2) << lt->tm_sec
				<< std::setfill(' ')
				<< "] ";
}

Account::Account(int initialDeposit) :
	_accountIndex(_nbAccounts),
	_amount(initialDeposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initialDeposit;

	// index:0;amount:42;created
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ":amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account()
{
	// index:0;amount:47;closed
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

int	Account::getNbAccounts() { return (_nbAccounts); }
int	Account::getTotalAmount() { return (_totalAmount); }
int	Account::getNbDeposits() { return (_totalNbDeposits); }
int	Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos()
{
	// accounts:8;total:12442;deposits:8;withdrawals:6
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::displayStatus() const
{
	// index:0;amount:47;deposits:1;withdrawals:0
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	previous = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << previous
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	previous = _amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout	<< "index:" << _accountIndex
					<< ";p_amount:" << previous
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << previous
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

int	Account::checkAmount() const
{
	return (_amount);
}