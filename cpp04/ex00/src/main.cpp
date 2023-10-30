/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:05 by nimai             #+#    #+#             */
/*   Updated: 2023/10/30 13:48:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void    wrong_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** WRONG TEST ********** = •ω• = meaw!" CLEAR<< std::endl;
    std::cout << std::endl;
    const WrongAnimal* meta = new WrongAnimal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound! 
    j->makeSound();
    meta->makeSound();
    delete (meta);
    delete (j);
    delete (i);
}


void    subject_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** SUBJECT TEST ********** U •x• U woof!" CLEAR<< std::endl;
    std::cout << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound! 
    j->makeSound();
    meta->makeSound();
    delete (meta);
    delete (j);
    delete (i);
}

int main() 
{
    subject_test();
    wrong_test();
    return 0;
}
