/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/09/05 15:11:02 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"
# define UTEST "TEST"
# define LTEST "test"

# include <iostream>

class ClapTrap 
{

private:
	std::string		_name;
	unsigned int	_hp = 10;
	unsigned int	_energy = 10;
	unsigned int	_damage = 0;

public:
	ClapTrap( void );
	ClapTrap( const int num );
	ClapTrap( const float numf );
	~ClapTrap( void );
	ClapTrap( const ClapTrap &src );
	ClapTrap &operator=( const ClapTrap &src );

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
// 	int			getRawBits( void ) const;
// 	void		setRawBits( int const raw );
// 	float		toFloat( void ) const;
// 	int 		toInt( void )const;

// //The 6 comparison operators: >, <, >=, <=, == and !=
// 	bool	operator>(const ClapTrap &src) const;
// 	bool	operator<(const ClapTrap &src) const;
// 	bool	operator>=(const ClapTrap &src) const;
// 	bool	operator<=(const ClapTrap &src) const;
// 	bool	operator==(const ClapTrap &src) const;
// 	bool	operator!=(const ClapTrap &src) const;

// //The 4 arithmetic operators: +, -, *, and /
// 	ClapTrap	operator+(const ClapTrap &src) const;
// 	ClapTrap	operator-(const ClapTrap &src) const;
// 	ClapTrap	operator*(const ClapTrap &src) const;
// 	ClapTrap	operator/(const ClapTrap &src) const;

// //The 4 increment/decrement (++i, i++, --i, i--) operators
// 	ClapTrap	&operator++( void );
// 	ClapTrap	&operator--( void );
// 	ClapTrap	operator++( int );
// 	ClapTrap	operator--( int );

// //overloaded member functions
// 	static ClapTrap& min( ClapTrap &a, ClapTrap &b );
// 	static const ClapTrap& min( const ClapTrap &a, const ClapTrap &b );
// 	static ClapTrap& max( ClapTrap &a, ClapTrap &b );
// 	static const ClapTrap& max( const ClapTrap &a, const ClapTrap &b );

};

std::ostream& operator<<(std::ostream &out, ClapTrap const &src);


#endif
