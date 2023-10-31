/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:05 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 11:21:22 by nimai            ###   ########.fr       */
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
    std::cout << GREEN "********** WRONG TEST ********** =•ω•= " CLEAR<< std::endl;
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

void    my_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** MY TEST ********** = •ω• = " CLEAR<< std::endl;
    std::cout << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdeas(0, "Fetch the ball");

    Dog dog2 = dog1; // Deep copy constructor
    // dog2.getBrain()->setIdeas(0, "Chase the squirrel");

    Dog dog3;
    dog3 = dog1; // Deep copy assignment operator
    dog1.getBrain()->setIdeas(0, "Say hello to my neighbor");
    std::cout << "dog1: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrain()->getIdeas(0) << std::endl;
    std::cout << "dog3: " << dog3.getBrain()->getIdeas(0) << std::endl;

    // Cat cat1;
    // cat1.getBrain->_ideas[0] = "Climb a tree";

    // Cat cat2 = cat1; // Deep copy constructor
    // cat2._brain->_ideas[0] = "Take a nap";

    // Cat cat3;
    // cat3 = cat1; // Deep copy assignment operator

}

void    subject_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** SUBJECT TEST ********** U •x• U " CLEAR<< std::endl;
    std::cout << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak 
    delete i;
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound! 
    // j->makeSound();
    // meta->makeSound();
    // delete (meta);
    // delete (j);
    // delete (i);
}

int main() 
{
    // subject_test();
    my_test();
    // wrong_test();
    return 0;
}
