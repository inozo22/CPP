/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:27:50 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 11:30:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAX_MATERIA 4

class Character: public ICharacter
{
	private:
			std::string _name;
			AMateria	*_materias[MAX_MATERIA];

	public:
			Character( void );
			Character( std::string name );
			Character( Character const &src );
			~Character();
			Character &operator=( const Character &src );

			std::string const & getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use (int idx, ICharacter& target);
};

#endif
