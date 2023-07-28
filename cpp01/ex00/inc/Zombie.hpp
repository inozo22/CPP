/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/07/28 11:18:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"

# include <iostream>

class Zombie {


public:

//	typedef Zombie		zombie;

	// static int	getNbAccounts( void );
	// static int	getTotalAmount( void );
	// static int	getNbDeposits( void );
	// static int	getNbWithdrawals( void );
	// static void	displayAccountsInfos( void );

	Zombie( void );
	~Zombie( void );

	void	announce( void );
    Zombie*	newZombie( std::string name );
    void	randomChump( std::string name );
	// bool	makeWithdrawal( int withdrawal );
	// int		checkAmount( void ) const;
	// void	displayStatus( void ) const;


private:
    std::string name;

	// static int	_nbAccounts;
	// static int	_totalAmount;
	// static int	_totalNbDeposits;
	// static int	_totalNbWithdrawals;

	// static void	_displayTimestamp( void );

	// int				_accountIndex;
	// int				_amount;
	// int				_nbDeposits;
	// int				_nbWithdrawals;

//	Zombie( void );

};

#endif
