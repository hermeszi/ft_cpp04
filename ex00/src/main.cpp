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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Proper Animals ===" << std::endl;
    Animal* const a = new Animal();
    Animal* const d = new Dog();
    Animal* const c = new Cat();

    std::cout << "a is a " << a->getType() << std::endl;
    std::cout << "d is a " << d->getType() << std::endl;
    std::cout << "c is a " << c->getType() << std::endl;

    std::cout << "a->makeSound(): ";
    a->makeSound();

    std::cout << "d->makeSound(): ";
    d->makeSound();

    std::cout << "c->makeSound(): ";
    c->makeSound();

    delete a;
    delete d;
    delete c;

    std::cout << "\n=== Wrong Animals ===" << std::endl;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << "wa is a " << wa->getType() << std::endl;
    std::cout << "wc is a " << wc->getType() << std::endl;

    std::cout << "wa->makeSound(): ";
    wa->makeSound();

    std::cout << "wc->makeSound(): ";
    wc->makeSound();  // Will call WrongAnimal's version, not WrongCat's!

    delete wa;
    delete wc;

    return (0);
}
