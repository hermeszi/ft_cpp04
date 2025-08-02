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

using std::string;
using std::endl;
using std::cout;

Cat::Cat() : Animal("Cat")
{
	cout << "Cat default constructor called" << endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    cout << "Cat copy constructor called" << endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    cout << "Cat assignment operator called" << endl;
    Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const
{
	cout << "     Meow! Meow!     " << endl;
}
