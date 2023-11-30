/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:19:59 by nimai             #+#    #+#             */
/*   Updated: 2023/11/30 15:59:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "colors.h"
#include <iostream>

int main( void )
{
    Data data = {.value = 12345, .str = "Hello world!"};
    uintptr_t   serializedPointer = serialize(&data);
    Data *      deserializedPointer = deserialize(serializedPointer);
    
    if (deserializedPointer == &data)
        std::cout << "Successful serialization and deserialization." << std::endl;
    else
        std::cout << "Failed serialization and deserialization." << std::endl;
    std::cout << "Original: " << data << std::endl;
    std::cout << "Pointer to data structure serialized as int: " << serializedPointer << std::endl;
    std::cout << "Deserialized: " << *deserializedPointer << std::endl;
     
    return (0);
}
