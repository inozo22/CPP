/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:05 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 14:31:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/IMateriaSource.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include <iostream>
#include "../inc/Cure.hpp"

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


	std::cout << BLUE "\n---Call Me Character constructor." RESET << std::endl;
	ICharacter* me = new Character("me");

	std::cout << BLUE "\n---Call MateriaSource constructor." RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << BLUE "\n---Learn Materia." RESET << std::endl;

	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	
	std::cout << BLUE "\n---Call Bob Character constructor." RESET << std::endl;
	ICharacter *bob = new Character("bob");
	std::cout << BLUE "\n---Call Materia constructor." RESET << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << BLUE "\n---Bob uses 0 materia, which is not set yet." RESET << std::endl;
	bob->use(0, *me);
	std::cout << BLUE "\n---Can I have more than 4???." RESET << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << BLUE "\n---I am going to throw a materia." RESET << std::endl;
	me->unequip(0);

	std::cout << BLUE "\n---Try to have the preview one. If there is no error message, I got it." RESET << std::endl;
	me->equip(tmp);


	
	std::cout << BLUE "\n---me uses 2 materias to Bob." RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << BLUE "\n---Create materia not existing and try to keep it." RESET << std::endl;

	tmp = src->createMateria("CURE");
	me->equip(tmp);

	tmp = src->createMateria("AJO");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	for (int i = 0; i < 5; i++)
		me->use(i, *bob);

	delete bob;
	delete me;
	delete src;

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

	// std::cout << std::endl << std::endl;
	// std::cout << "********** SUBJECT TEST **********"<< std::endl;
	// std::cout << std::endl;

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
// void    subject_test()
// {

// 	// std::cout << std::endl << std::endl;
// 	// std::cout << "********** SUBJECT TEST **********"<< std::endl;
// 	// std::cout << std::endl;

// 	IMateriaSource* src = new MateriaSource();
// 	AMateria *ice = new Ice();
// 	AMateria *cure = new Cure();
	
// 	src->learnMateria(ice);
// 	src->learnMateria(cure);

// 	delete ice;
// 	delete cure;

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter *bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;
// }

int main() 
{
    // subject_test();
	// bad_state_test();
    my_test();
    // array_test();
    return 0;
}
