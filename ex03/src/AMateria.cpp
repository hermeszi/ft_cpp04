/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

using std::string;
using std::endl;
using std::cout;

AMateria::AMateria() : type("AMateria")
{
	cout << "AMateria default constructor called" <<endl;
}

AMateria::AMateria(string name) : type(name)
{
	cout << "AMateria constructor called for " << type << endl;
}

AMateria::AMateria	(const AMateria& copy)
{
	cout << "AMateria Copy constructor called" << endl;
	*this = copy;
}

AMateria& AMateria::operator= (const AMateria& other)
{
	cout << "AMateria Copy Assignment operator called" << endl;
	if (this != &other)
	{
		this->type 	= other.getType();
	}
	return (*this);
}

AMateria::~AMateria()
{
	cout << "AMateria destructor called for " << type << endl;
}

const string& AMateria::getType() const
{
	return (this->type);
}

void	AMateria::setType(string name)
{
	this->type = name;
}

void	AMateria::use(ICharacter& target)
{
	cout << "AMateria use called on " << target.getName() << ": Nothing happens..." << endl;
}
