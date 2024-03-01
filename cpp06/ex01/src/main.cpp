/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:19:59 by nimai             #+#    #+#             */
/*   Updated: 2024/03/01 13:36:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>

int main()
{
    // Create a Data object
    Data dataObj(23423);

    // Serialize the pointer to the Data object
    uintptr_t serialized = Serializer::serialize(&dataObj);

    // Deserialize the uintptr_t back to a pointer
    Data* deserialized = Serializer::deserialize(serialized);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserialized == &dataObj) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "&dataObj: " << &dataObj << std::endl;
        std::cout << "deserialized: " << deserialized << std::endl;
        std::cout << "serialized: " << serialized << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
        std::cout << "&dataObj: " << &dataObj << std::endl;
        std::cout << "deserialized: " << deserialized << std::endl;
        std::cout << "serialized: " << serialized << std::endl;
    }

    std::cout << "deserialized: " << deserialized->value << std::endl;
    std::cout << "dataObj: " << dataObj.value << std::endl;

    return 0;
}
