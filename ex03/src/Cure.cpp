/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

using std::endl;
using std::cout;

Cure::Cure() : AMateria("Cure")
{
	cout << "Cure default constructor called" << endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    cout << "Cure copy constructor called" << endl;
}

Cure& Cure::operator=(const Cure& other) 
{
    cout << "Cure copy assignment operator called" << endl;
    AMateria::operator=(other);
    return (*this);
}

Cure::~Cure()
{
    cout << "Cure destructor called" << endl;
}

AMateria* Cure::clone() const
{
    cout << "Cloning Cure" << endl;
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
