/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:22:06 by nimai             #+#    #+#             */
/*   Updated: 2023/07/27 17:58:54 by nimai            ###   ########.fr       */
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
		Account::_totalAmount += initial_deposit;
	}
	
	Account::~Account(void)
	{
		
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
		std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
		std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawls:" << Account::_totalNbWithdrawals << std::endl;
	}
	
	void	Account::makeDeposit(int deposit)
	{
		(void)deposit;
		
	}
	
	bool	Account::makeWithdrawal(int withdrawal)
	{
		(void)withdrawal;
		return 0;
	}
	
	int		Account::checkAmount(void) const
    {
        return 0;
	}
	
	void	Account::displayStatus(void) const
    {

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
