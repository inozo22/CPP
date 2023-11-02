#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__

# include <iostream>
# include <string>
# include "MateriaSource.hpp"
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
