/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:11:48 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 11:31:35 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
	private:
			AMateria    *_materias[MAX_MATERIA];
	public:
			MateriaSource( void );
			MateriaSource( MateriaSource const & src);
			~MateriaSource( void );

			MateriaSource & operator=(MateriaSource const & src);

			void learnMateria( AMateria *newOne);
			AMateria* createMateria( std::string const & type );

};

#endif
