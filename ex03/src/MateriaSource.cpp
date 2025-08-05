/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define SLOT_COUNT 4

using std::string;
using std::endl;
using std::cout;

MateriaSource::MateriaSource() 
{
	cout << "MateriaSource default constructor called" <<endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
    	slots[i] = NULL;
}

MateriaSource::MateriaSource	(const MateriaSource& copy)
{
	cout << "MateriaSource Copy constructor called" << endl;
    for (int i = 0; i < SLOT_COUNT; ++i)
        slots[i] = copy.getMateria(i)->clone();
}

MateriaSource& MateriaSource::operator= (const MateriaSource& other)
{
	cout << "MateriaSource Copy Assignment operator called" << endl;
	if (this != &other)
	{
		for (int i = 0; i < SLOT_COUNT; ++i)
		{
			delete this->slots[i];
			this->slots[i] = other.getMateria(i)->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	cout << "MateriaSource destructor called" << endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
	{
		delete slots[i];
		slots[i] = NULL;
	}
}

AMateria*	MateriaSource::getMateria(int index) const
{
	return (this->slots[index]);
}

void MateriaSource::setMateria(int index, AMateria* materia)
{
	if (index >= 0 && index < SLOT_COUNT)
	{
		delete this->slots[index];
		this->slots[index] = materia;
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	cout << "MateriaSource::learnMateria called" << endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
	{
		if (slots[i] == NULL)
		{
			slots[i] = materia;
			cout << "Learned new materia <" << materia->getType() << "> in slot " << i << endl;
			return;
		}
	}
	cout << "No empty slots available to learn new materia" << endl;
}

AMateria* MateriaSource::createMateria(string const & type)
{
	cout << "CreateMateria called for type: " << type << endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
	{
		if (slots[i] && slots[i]->getType() == type)
		{
			cout << "Found materia in slot " << i << ", creating it..." << endl;
			return slots[i]->clone();
		}
	}
	cout << "No learned materia matches type: " << type << endl;
	return NULL;
}
