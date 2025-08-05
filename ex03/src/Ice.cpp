/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/05 18:50:05 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Character.hpp" 

using std::endl;
using std::cout;

Ice::Ice() : AMateria("ice")
{
	cout << "Ice default constructor called" << endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    cout << "Ice copy constructor called" << endl;
}

Ice& Ice::operator=(const Ice& other) 
{
    cout << "Ice assignment operator called" << endl;
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice()
{
    cout << "Ice destructor called" << endl;
}

AMateria* Ice::clone() const
{
    cout << "Cloning Ice" << endl;
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
