#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
            MateriaSource( void );
            MateriaSource( MateriaSource const & src);
            ~MateriaSource( void );

            MateriaSource & operator=(MateriaSource const & src);

            void learnMateria( AMateria * );
            AMateria* createMateria( std::string const & type );

    private:
            
};

#endif
