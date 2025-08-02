/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using std::string;
using std::endl;
using std::cout;

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << "WrongCat default constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    cout << "WrongCat copy constructor called" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    cout << "WrongCat assignment operator called" << endl;
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    cout << "WrongCat destructor called" << endl;
}

void WrongCat::makeSound() const
{
	cout << "     Meow! Meow!     " << endl;
}
