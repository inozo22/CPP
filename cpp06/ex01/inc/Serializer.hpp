#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
			Serializer( void );  // Private constructor to prevent instantiation
			Serializer( Serializer const & src );  // Private constructor to prevent instantiation
			Serializer & operator=( const Serializer &src );

	public:
			~Serializer( void );  // Destructor
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
