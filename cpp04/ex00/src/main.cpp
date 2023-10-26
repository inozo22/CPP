/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:05 by nimai             #+#    #+#             */
/*   Updated: 2023/10/26 16:58:13 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

void    subject_test()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    // const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound! 
    j->makeSound();
    meta->makeSound();
    delete (meta);
    delete (j);
}

int main() 
{
    subject_test();
    return 0;
}
