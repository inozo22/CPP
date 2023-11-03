/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:05 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 14:48:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//#define ANIMAL_AMOUNT 10

void    array_test()
{
	std::cout << std::endl << std::endl;
	std::cout << GREEN "********** ARRAY TEST ********** U •x• U " RESET<< std::endl;
	std::cout << std::endl;

/*	AAnimal* animalArray[ANIMAL_AMOUNT + 1];
	animalArray[ANIMAL_AMOUNT] = NULL;
	std::cout << BLUE "How to keep dogs and cats?-----" RESET << std::endl;
	std::cout << MAGENTA "-----The important thing is that don't keep more than you can take care." RESET << std::endl;
	for (int i = 0; i < ANIMAL_AMOUNT; i++)
	{
		if (i % 2 == 0)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}
	std::cout << BLUE "I think I welcame too many... they are so loud...-----" RESET << std::endl;
	std::cout << MAGENTA "-----I said to you..." RESET << std::endl;	
	for (int i = 0; i < ANIMAL_AMOUNT; i++)
	{
		animalArray[i]->makeSound();
	}
	std::cout << BLUE "I decided to find new family for all of them-----" RESET << std::endl;
	std::cout << MAGENTA "-----OK..." RESET << std::endl;	
    for (int i = 0; i < ANIMAL_AMOUNT; i++)
	{
		delete (animalArray[i]);
	}*/
}

void    my_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** MY TEST ********** = •ω• = " RESET<< std::endl;
    std::cout << std::endl;
/*    Dog dog1;
    dog1.getBrain()->setIdeas(0, "Is it time for a walk?");

    Dog dog2 = dog1; // Deep copy constructor
    // dog2.getBrain()->setIdeas(0, "Chase the squirrel");

    Dog dog3;
    dog3 = dog1; // Deep copy assignment operator
    dog1.getBrain()->setIdeas(0, "I love my human.");
    std::cout << "dog1: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrain()->getIdeas(0) << std::endl;
    std::cout << "dog3: " << dog3.getBrain()->getIdeas(0) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdeas(0, "Time for a nap.");

    Cat cat2 = cat1; // Deep copy constructor
    cat2.getBrain()->setIdeas(0, "Pet me, human.");

    Cat cat3;
    cat3 = cat1; // Deep copy assignment operator
    std::cout << "cat1: " << cat1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "cat2: " << cat2.getBrain()->getIdeas(0) << std::endl;
    std::cout << "cat3: " << cat3.getBrain()->getIdeas(0) << std::endl;*/

}

void    bad_state_test()
{

    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** BAD STATE TEST ********** = •ω• = " RESET<< std::endl;
    std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	for (int i = 0; i < 5; i++)
	{
		src->learnMateria(new Ice());	
	}

	ICharacter* me = new Character("Badman");

	AMateria* tmp;
	tmp = src->createMateria("icy");
	me->equip(tmp);
	tmp = src->createMateria("Cure");
	me->equip(tmp);

	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{
			tmp = src->createMateria("cure");	
			me->equip(tmp);
		}
		else
		{
			tmp = src->createMateria("ice");
			me->equip(tmp);	
		}
	}
	me->equip(NULL);	


	ICharacter *bob = new Character("Hero");

	me->use(-1, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(7894561, *bob);
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{
			tmp = src->createMateria("ice");	
			me->equip(tmp);
		}
		else
		{
			tmp = src->createMateria("cure");
			me->equip(tmp);	
		}
	}
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;
}

void    subject_test()
{

    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** SUBJECT TEST ********** U •x• U " RESET<< std::endl;
    std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main() 
{
    // subject_test();
	bad_state_test();
    // my_test();
    // array_test();
    return 0;
}
