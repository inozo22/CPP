/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 16:14:18 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"
# include <string>

class WrongCat : public WrongAnimal
{
	public:
			WrongCat( void );
			WrongCat( std::string type );
			WrongCat( WrongCat const &src );
			~WrongCat( void );
			WrongCat &operator=( const WrongCat &src );

			// std::string		getType(void) const;

   			void    makeSound( void ) const;
			std::string	getSound( void ) const;

};
// std::ostream&	operator<<(std::ostream &out, Cat const &src);

#endif
