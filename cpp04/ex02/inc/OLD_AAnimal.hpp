/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 15:28:27 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

// # define BLUE "\033[1;34m"
// # define YELLOW "\033[1;33m"
// # define RED "\033[1;31m"
// # define CYAN "\033[1;36m"
// # define GREEN "\033[1;32m"
// # define MAGENTA "\033[1;35m"
// # define CLEAR "\033[0m"
// # define UTEST "TEST"
// # define LTEST "test"

# define DEFAULT_AANIMAL "Bird"
# define DOG_SOUND "Woof woof woof!"
# define CAT_SOUND "Meaw meaw meaw"

# include <iostream>
# include <string>
# include "colors.h"

class AAnimal 
{

protected:
	std::string		type;

public:
	AAnimal( void );
	AAnimal( std::string type );
	// AAnimal( AAnimal const &src );
	virtual ~AAnimal( void );
	AAnimal &operator=( const AAnimal &src );

	// std::string		getType(void) const;

    virtual void    makeSound( void ) const = 0;
	
};

#endif
