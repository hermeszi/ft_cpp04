/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/05 18:56:29 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using std::string;
using std::endl;
using std::cout;

Animal::Animal() : type("Animal")
{
	cout << "Animal default constructor called" <<endl;
}

Animal::Animal(string name) : type(name)
{
	cout << "Animal constructor called for " << type << endl;
}

Animal::Animal	(const Animal& copy)
{
	cout << "Animal Copy constructor called" << endl;
	*this = copy;
}

Animal& Animal::operator= (const Animal& other)
{
	cout << "Animal Copy Assignment operator called" << endl;
	if (this != &other)
	{
		this->type 	= other.getType();
	}
	return (*this);
}

Animal::~Animal()
{
	cout << "Animal destructor called for " << type << endl;
}

string	Animal::getType() const
{
	return (this->type);
}

void	Animal::setType(string name)
{
	this->type = name;
}

void	Animal::makeSound() const
{
	cout << "Animal echoes silently through time..." << endl;
}
