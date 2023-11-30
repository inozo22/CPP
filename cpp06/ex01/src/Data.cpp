/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:05 by nimai             #+#    #+#             */
/*   Updated: 2023/11/30 16:00:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <iomanip>

uintptr_t   serialize( Data * ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data *  deserialize( uintptr_t raw )
{
    return (reinterpret_cast<Data *>(raw));
}
std::ostream & operator<<( std::ostream &os, const Data & obj )
{
    os << "Data structure stored at: " << &obj << "\n" << std::setfill(' ') << std::setw(8) << "value: " << obj.value
    << "\n" << std::setfill(' ') << std::setw(8) << "string: " << obj.str;
    return (os);
}

// Data::Data( void )
// {
	
// }

//class Data
// {
//     unsigned int    value;
//     std::string     str;	
// };
// uintptr_t   serialize( Data * ptr );
// Data *      deserialize( uintptr_t raw );
// std::ostream &  operator<<( std::ostream &os, const Data & obj );

// os << "\n" << std::setfill(' ') << std::setw(8) << "double: "
