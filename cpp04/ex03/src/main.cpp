/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:05 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 16:07:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define ANIMAL_AMOUNT 10

void    array_test()
{
	std::cout << std::endl << std::endl;
	std::cout << GREEN "********** ARRAY TEST ********** U •x• U " RESET<< std::endl;
	std::cout << std::endl;

	AAnimal* animalArray[ANIMAL_AMOUNT + 1];
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
	}
}

void    my_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** MY TEST ********** = •ω• = " RESET<< std::endl;
    std::cout << std::endl;
    Dog dog1;
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
    std::cout << "cat3: " << cat3.getBrain()->getIdeas(0) << std::endl;

}

void    subject_test()
{
    std::cout << std::endl << std::endl;
    std::cout << GREEN "********** SUBJECT TEST ********** U •x• U " RESET<< std::endl;
    std::cout << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;//should not create a leak 
    delete i;
    // const AAnimal* meta = new AAnimal();
    // const AAnimal* j = new Dog();
    // const AAnimal* i = new Cat();
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
    // my_test();
    array_test();
    return 0;
}

// 100 things that your dog might think about:

// I'm hungry.
// Is it time for a walk?
// I love my human.
// Where did the ball go?
// Squirrel!
// Can I have a treat?
// Belly rub, please.
// Why are they leaving without me?
// I need to mark my territory.
// This couch is comfy.
// What's that smell?
// Time for my afternoon nap.
// Let's play fetch!
// Who's at the door?
// Why are they upset?
// I miss my dog friend.
// Is it dinner time yet?
// I want to go to the park.
// I hear thunder, I'm scared.
// I love car rides.
// Time to protect the house.
// I should chase my tail.
// My toys are the best.
// I smell another dog.
// Where's my favorite chew toy?
// Why are they talking to me in that silly voice?
// It's time to dig a hole.
// I need to sniff everything on this walk.
// I wish I could catch that bird.
// I love it when they scratch behind my ears.
// Who's that person on the TV?
// I should bark at the mail carrier.
// I wonder what's in the trash can.
// I need to mark that tree.
// This grass feels nice on my paws.
// Can I have some of their food?
// I love rolling in the grass.
// I'm the best dog in the world.
// Time to chase my shadow.
// I need to protect the yard from squirrels.
// I don't like baths.
// What's that noise outside?
// I should go for a swim.
// I love when they scratch my belly.
// I'm so excited to see them come home.
// I hope they take me on the next trip.
// I need to guard my toys.
// I wonder where my human went.
// Time for a game of tug-of-war.
// I want to cuddle on the couch.
// Why is the doorbell ringing?
// I wish I could catch that frisbee.
// Who's that dog in the mirror?
// I should go find my leash.
// I love the smell of the outdoors.
// Time for a game of hide and seek.
// I hope they share their sandwich.
// I'm tired, time for a nap.
// I want to explore the backyard.
// I should greet the neighbor's dog.
// I'm curious about that squirrel on the tree.
// Why is the vacuum so scary?
// I miss my puppy days.
// I need to protect the house from the evil broom.
// I want to go for a car ride.
// I wish I could catch that butterfly.
// Time for a game of catch.
// I should give them a wet, sloppy kiss.
// I love when they scratch my back.
// I hope they drop some food while cooking.
// I need to guard my food bowl.
// I'm excited for my daily walk.
// Who's that person at the door?
// I wonder what's on the other side of the fence.
// I should investigate that strange noise.
// I'm a good boy/girl.
// I want to lie in the sun.
// I hope they let me sleep on the bed tonight.
// I love when they play with me.
// I'm so happy when they come home.
// I should chase my own tail for fun.
// I miss my doggy friends at the park.
// Time for a game of tag.
// I want to lick their face.
// I need to protect the backyard from birds.
// I wish I could join them on the couch.
// I'm curious about the sound of the doorbell.
// Why is the vacuum cleaner so loud?
// I love when they take me for a ride.
// I hope they share their ice cream.
// I need to keep an eye on the yard.
// I'm excited to see other dogs on our walk.
// I should play with my squeaky toys.
// I want to snuggle under the blankets.
// I'm the best companion they could ask for.
// I miss playing in the snow.
// Time for a game of "find the treat."
// I need to keep the family safe.
// I love when they scratch my chin.
// I'm ready for another adventure.

// 100 things your cat might "think" about:

// I'm hungry.
// Time for a nap.
// Pet me, human.
// Why did they move my favorite toy?
// Birds outside are so interesting.
// I love to scratch this furniture.
// Time for a hunting expedition.
// I should groom myself.
// The sunbeam is my favorite spot.
// I wish they'd open the door.
// Where's my cozy hideout?
// I want to play with that shoelace.
// Mice are fascinating creatures.
// I need to sharpen my claws.
// Let's knock things off the table.
// I'm the ruler of this domain.
// Who's that strange cat outside?
// Why is the dog so hyper?
// Dinner time can't come soon enough.
// I'm not sure I like that new food.
// Why are they ignoring me?
// I need to pounce on the moving shadows.
// I should curl up in a small box.
// I'm not a fan of the vacuum cleaner.
// Let's explore every nook and cranny.
// I should bring them a "gift."
// I'm so comfy on this soft blanket.
// Who's that person at the door?
// I want to climb to the highest shelf.
// I'm not in the mood for cuddles right now.
// Why is that fly buzzing around?
// Let's chase my tail for a while.
// I need to stretch my legs.
// I'm not a fan of the thunderstorm.
// What's that delicious smell from the kitchen?
// I wish I could catch that elusive laser dot.
// I'm the stealthiest predator in the house.
// Why is that curtain so tempting to play with?
// Dinner should be served promptly.
// I'm the cutest cat in the world.
// I should hide and ambush my human.
// I want to find a cozy lap to sit on.
// I'm not sure I like the new scratching post.
// Let's explore the dark, mysterious closet.
// I need to keep an eye on the neighborhood.
// I'm the best at knocking over cups.
// I'm feeling frisky, time for a sprint.
// Why is the dog always in my space?
// I should watch the fish swim.
// I want to climb the tallest tree.
// I'm not a fan of the rain.
// I wish they'd open the window.
// Let's chase that feather toy.
// I'm the master of the litter box.
// I need to curl up in a sunbeam.
// I'm the boss of my territory.
// I'm not sure about this new cat food.
// Why is that squirrel taunting me from outside?
// I should hide and wait for the perfect pounce.
// I want to curl up on a warm lap.
// I'm not a fan of the loud music.
// Let's stalk the shoelaces again.
// I need to claim that cardboard box as mine.
// I'm the guardian of the windowsill.
// I wish they'd leave me alone for a while.
// I should play with my jingling bell toy.
// I'm not sure about the new cat tower.
// Why is that butterfly fluttering outside?
// I should bat at that curtain tassel.
// I want to find a cozy spot on the bookshelf.
// I'm not in the mood for company.
// I'm the queen of the couch.
// I wish they'd stop taking pictures of me.
// Let's explore the empty paper bag.
// I need to claim the computer keyboard.
// I'm the stealthy ninja of the house.
// I'm not a fan of the strange cat on the internet.
// Why is that bug crawling on the wall?
// I should chase my own shadow.
// I want to curl up on their bed.
// I'm the chief bird-watcher.
// I'm not sure about that loud car outside.
// Let's scratch at the door to go out.
// I need to claim the entire bed.
// I'm the ruler of the nighttime.
// I wish they'd turn off the lights.
// I'm not in the mood for that noisy toy.
// Why is that plant so tempting to chew on?
// I should curl up in my cozy cat bed.
// I want to catch that mysterious red dot.
// I'm not a fan of the bath.
// Let's hide in the closet and surprise them.
// I need to keep a watchful eye on the TV.
// I'm the guardian of the food bowl.
// I'm not sure about that big, noisy box (vacuum cleaner).
// Why is that dog always barking next door?
// I should knead the softest blanket.
// I want to chase the reflections from the watch.
// I'm not in the mood for visitors.
// I'm the happiest when they give me chin scratches.
