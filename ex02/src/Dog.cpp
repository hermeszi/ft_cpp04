/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using std::endl;
using std::cout;

Dog::Dog() : AAnimal("Dog")
{
	cout << "Dog default constructor called" << endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    cout << "Dog copy constructor called" << endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) 
{
    cout << "Dog copy assignment operator called" << endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }

    return (*this);
}

Dog::~Dog()
{
    cout << "Dog destructor called" << endl;
    delete brain;
}

Brain* Dog::getBrain() const
{
    return brain;
}

void Dog::makeSound() const
{
	cout << "     Woof! Woof!     " << endl;
}
