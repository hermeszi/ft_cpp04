/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

using std::string;
using std::endl;
using std::cout;

AAnimal::AAnimal() : type("AAnimal")
{
	cout << "AAnimal default constructor called" <<endl;
}

AAnimal::AAnimal(string name) : type(name)
{
	cout << "AAnimal constructor called for " << type << endl;
}

AAnimal::AAnimal	(const AAnimal& copy)
{
	cout << "AAnimal Copy constructor called" << endl;
	*this = copy;
}

AAnimal& AAnimal::operator= (const AAnimal& other)
{
	cout << "AAnimal Copy Assignment operator called" << endl;
	if (this != &other)
	{
		this->type 	= other.getType();
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	cout << "AAnimal destructor called for " << type << endl;
}

string	AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::setType(string name)
{
	this->type = name;
}

// void	AAnimal::makeSound() const
// {
// 	cout << "AAnimal echoes silently through time..." << endl;
// }
