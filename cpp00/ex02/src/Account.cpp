/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:22:06 by nimai             #+#    #+#             */
/*   Updated: 2023/07/26 15:41:16 by nimai            ###   ########.fr       */
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
		(void)initial_deposit;
		_accountIndex = Account::getNbAccounts();
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
		std::cout << "I'm in displayAccountsInfos" << std::endl;
		_displayTimestamp();
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
		    std::time_t result = std::time(nullptr);
    		std::cout << std::put_time(std::localtime(&result)) << std::endl;
			//230726: Time display doesn't work yet

	}
