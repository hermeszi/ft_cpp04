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

Dog::Dog() : Animal("Dog")
{
	cout << "Dog default constructor called" << endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    cout << "Dog copy constructor called" << endl;
}

Dog& Dog::operator=(const Dog& other) 
{
    cout << "Dog copy assignment operator called" << endl;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const
{
	cout << "     Woof! Woof!     " << endl;
}
