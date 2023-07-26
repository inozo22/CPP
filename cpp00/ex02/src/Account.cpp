/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:22:06 by nimai             #+#    #+#             */
/*   Updated: 2023/07/26 14:00:55 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <string>
#include <iostream>


	Account::Account(int initial_deposit)
	{
		(void)initial_deposit;
	}
	Account::~Account(void)
	{
		
	}
	int	Account::getNbAccounts(void)
	{
		return 0;
	}
	int	Account::getTotalAmount(void)
	{
		return 0;
	}
	int	Account::getNbDeposits(void)
	{
		return 0;
	}
	int	Account::getNbWithdrawals(void)
	{
		return 0;
	}
	void	Account::displayAccountsInfos(void)
	{
		std::cout << "I'm in displayAccountsInfos" << std::endl;
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
