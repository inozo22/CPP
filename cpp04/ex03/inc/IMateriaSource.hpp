/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:23:13 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 12:23:15 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__

// # include <iostream>
# include <string>
// # include "MateriaSource.hpp"
# include "AMateria.hpp"
# include "colors.h"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(){}
		virtual void learnMateria( AMateria * ) = 0;
		virtual AMateria* createMateria( std::string const & type ) = 0;
};
#endif
