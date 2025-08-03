/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using std::string;
using std::endl;
using std::cout;

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	cout << "WrongAnimal default constructor called" <<endl;
}

WrongAnimal::WrongAnimal(string name) : type(name)
{
	cout << "WrongAnimal constructor called for " << type << endl;
}

WrongAnimal::WrongAnimal	(const WrongAnimal& copy)
{
	cout << "WrongAnimal Copy constructor called" << endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	cout << "WrongAnimal Copy Assignment operator called" << endl;
	if (this != &other)
	{
		this->type 	= other.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called for " << type << endl;
}

string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::setType(string name)
{
	this->type = name;
}

void	WrongAnimal::makeSound() const
{
	cout << "WrongAnimal echoes silently through time..." << endl;
}
