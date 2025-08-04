/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // AAnimal test; // 🤔
    // AAnimal* ptr = new AAnimal(); // 🤔

    std::cout << " === Creating Cat and Dog (heap) ==== " << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    std::cout << " === Creating array of AAnimal pointers of Cat and Dog (heap) === " << std::endl;
    AAnimal* zoo[10];
    std::cout << " === Dogs === " << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        zoo[i] = new Dog();
        std::cout << zoo[i]->getType() << i << " : "  << std::endl;
        zoo[i]->makeSound();
    }
    std::cout << " === Cats === " << std::endl;
    for (int i = 5; i < 10; ++i)
    {
        zoo[i] = new Cat();
        std::cout << zoo[i]->getType() << i << " : " << std::endl;
        zoo[i]->makeSound();
    }
    for (int i = 0; i < 10; ++i)
        delete zoo[i];

    std::cout << " === Test deep copy === " << std::endl;
    Dog original;
    original.getBrain()->setIdeas(0, "Bone");
    Dog clone = original;
    original.getBrain()->setIdeas(0, "Home");
    std::cout << "\nORIGINAL thinking of : " << original.getBrain()->getIdeas(0) << std::endl;
    std::cout << "COPY still thinking of : "<< clone.getBrain()->getIdeas(0) << std::endl;
    std::cout << std::endl;

    return (0);
}
