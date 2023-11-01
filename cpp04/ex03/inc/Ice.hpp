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

# include "AMaterial.hpp"
# include "Brain.hpp"
# include <string>

class Ice : public AMaterial
{
public:
	Ice( void );
	Ice( std::string type );
	Ice( Ice const &src );
	~Ice( void );
	Ice &operator=( const Ice &src );

    Brain*		getBrain(void) const;

	// std::string		getType(void) const;

    void    makeSound( void ) const;
	void	use(ICharacter& target);


private:
	Brain * _brain;
};

#endif
