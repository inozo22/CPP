/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:22:06 by nimai             #+#    #+#             */
/*   Updated: 2023/07/27 18:46:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <ctime>

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

	Account::Account(int initial_deposit)
	{
		Account::_accountIndex = Account::getNbAccounts();
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex;
		std::cout << ";amount:" << initial_deposit << ";created" << std::endl;
		Account::_nbAccounts++;
		Account::_amount = initial_deposit;
		Account::_totalAmount += initial_deposit;
	}

	Account::~Account(void)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::checkAmount() << ";closed" << std::endl;
	}

	int	Account::getNbAccounts(void)
	{
		return (_nbAccounts);
	}

	int	Account::getTotalAmount(void)
	{
		return (_totalAmount);
	}

	int	Account::getNbDeposits(void)
	{
		return (_totalNbDeposits);
	}

	int	Account::getNbWithdrawals(void)
	{
		return (_totalNbWithdrawals);
	}

	void	Account::displayAccountsInfos(void)
	{
		Account::_displayTimestamp();
		std::cout << BLUE << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
		std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawls:" << Account::_totalNbWithdrawals << CLEAR << std::endl;
	}
	
	void	Account::makeDeposit(int deposit)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";deposit:" << deposit;
		Account::_amount += deposit;
		Account::_nbDeposits++;
		std::cout << ";amount:" << Account::_amount << ";nb_deposits:" << Account::_nbDeposits << CLEAR <<std::endl;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
	}
	
	bool	Account::makeWithdrawal(int withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount;
		if ((Account::_amount - withdrawal) < 0)
		{
			std::cout << ":refused" << CLEAR << std::endl;
			return false;
		}
		Account::_nbWithdrawals++;
		Account::_amount -= withdrawal;
		std::cout << ";amount:" << Account::_amount << ";nb_withdrawls:" << Account::_nbWithdrawals << CLEAR <<std::endl;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return true;
	}
	
	int		Account::checkAmount(void) const
    {
        return (Account::_amount);
	}
	
	void	Account::displayStatus(void) const
    {
	//	std::cout << _accountIndex << "hello" << std::endl;
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount;
		std::cout << ";deposits:" << Account::_nbDeposits << ";withdrawls:" << Account::_nbWithdrawals << std::endl;
    }

	void	Account::_displayTimestamp(void)
	{
		struct timespec ts;
		struct tm t;
		int ret;
	
		ret = clock_gettime(CLOCK_REALTIME, &ts);
		if (ret < 0)
		{
			perror("clock_gettime fail.");
		}
		localtime_r(&ts.tv_sec, &t);
		char buf[32];
		ret = strftime(buf, 32, "[%Y%m%d_%H%M%S]", &t);
		if (ret == 0)
		{
			perror("strftime fail.");
		}
		std::cout << buf << " ";
	}
