/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 10:47:12 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public AAnimal
{
	private:
			Brain	* _brain;
	public:
			Cat( void );
			Cat( std::string type );
			Cat( Cat const &src );
			~Cat( void );
			Cat &operator=( const Cat &src );

			// std::string		getType(void) const;

   			void		makeSound( void ) const;
			std::string	getSound( void ) const;
			Brain*		getBrain(void) const;

};
// std::ostream&	operator<<(std::ostream &out, Cat const &src);

#endif
