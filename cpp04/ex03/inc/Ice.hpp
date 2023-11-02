/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/11/01 12:29:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Ice : public AMaterial
{
public:
	Ice( void );
//	Ice( std::string type );
	Ice( Ice const &src );
	~Ice( void );
	Ice &operator=( const Ice &src );

//	std::string	const &getType(void) const;
	AMateria *	clone(void) const;

	void	use(ICharacter& target);

private:
	Brain * _brain;
};

#endif
