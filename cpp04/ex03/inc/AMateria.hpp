/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 15:28:27 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

// # define BLUE "\033[1;34m"
// # define YELLOW "\033[1;33m"
// # define RED "\033[1;31m"
// # define CYAN "\033[1;36m"
// # define GREEN "\033[1;32m"
// # define MAGENTA "\033[1;35m"
// # define CLEAR "\033[0m"
// # define UTEST "TEST"
// # define LTEST "test"

# include <iostream>
# include <string>
# include "colors.h"
# include "ICharacter.hpp"

class AMateria 
{

protected:
	std::string		type;

public:
	AMateria( void );
	AMateria( std::string const & type );
	AMateria( AMateria const &src );
	virtual ~AMateria( void );
	AMateria &operator=( const AMateria &src );

	std::string	const &	getType() const; //Returns the materia type

    virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	
};

#endif
