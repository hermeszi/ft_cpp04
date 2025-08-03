/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using std::endl;
using std::cout;

Cat::Cat() : Animal("Cat")
{
	cout << "Cat default constructor called" << endl;
    brain = new Brain ();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    cout << "Cat copy constructor called" << endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) 
{
    cout << "Cat assignment operator called" << endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    cout << "Cat destructor called" << endl;
    delete brain;
}

Brain* Cat::getBrain() const
{
    return brain;
}

void Cat::makeSound() const
{
	cout << "     Meow! Meow!     " << endl;
}
