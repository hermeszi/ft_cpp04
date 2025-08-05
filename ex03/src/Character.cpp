/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define SLOT_COUNT 4
#define MAX_LOST 20

using std::string;
using std::endl;
using std::cout;

Character::Character() : name("Default PLAYER"), lost_count(0)
{
	cout << "Character default constructor called" <<endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
    	slots[i] = NULL;
    for (int i = 0; i < MAX_LOST; ++i)
		lostAndFound[i] = NULL;
}

Character::Character(string name) : name(name),  lost_count(0)
{
	cout << "Character constructor called for "<< this->name <<endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
    	slots[i] = NULL;
    for (int i = 0; i < MAX_LOST; ++i)
		lostAndFound[i] = NULL;
}

Character::Character	(const Character& copy) : name(copy.getName()), lost_count(copy.getLostCount())
{
	//cout << "Character Copy constructor called" << endl;
    for (int i = 0; i < SLOT_COUNT; ++i)
    {
        if (copy.slots[i])
            slots[i] = copy.getMateria(i)->clone();
        else
            slots[i] = NULL;
    }
    for (int i = 0; i < MAX_LOST; ++i)
    {
        if (copy.lostAndFound[i])
		    this->lostAndFound[i] = copy.getLostFound(i)->clone();
        else
            lostAndFound[i] = NULL;
    }
}

Character& Character::operator= (const Character& other)
{
	//cout << "Character Copy Assignment operator called" << endl;
	if (this != &other)
	{
        this->name = other.getName();
        this->lost_count = other.getLostCount();
		for (int i = 0; i < SLOT_COUNT; ++i)
		{
			delete this->slots[i];
		    if (other.slots[i])
		        this->slots[i] = other.getMateria(i)->clone();
            else
                this->slots[i] = NULL;
		}
        for (int i = 0; i < MAX_LOST; ++i)
        {
            delete this->lostAndFound[i];
            if (other.lostAndFound[i])
		        this->lostAndFound[i] = other.getLostFound(i)->clone();
            else
                this->lostAndFound[i] = NULL;
        }
	}
	return (*this);
}

Character::~Character()
{
	cout << "Character " << this->name << " destructor called" << endl;
	for (int i = 0; i < SLOT_COUNT; ++i)
	{
        if (slots[i])
            delete slots[i];
		slots[i] = NULL;
	}
    for (int i = 0; i < MAX_LOST; ++i)
    {
        if (lostAndFound[i])
            delete lostAndFound[i];
		lostAndFound[i] = NULL;
    }
}

const string& Character::getName() const
{
    return (this->name);
}

const int& Character::getLostCount() const
{
    return (this->lost_count);
}

AMateria*	Character::getMateria(int index) const
{
	return (this->slots[index]);
}

AMateria*	Character::getLostFound(int index) const
{
	return (this->lostAndFound[index]);
}

void Character::setMateria(int index, AMateria* materia)
{
	if (index >= 0 && index < SLOT_COUNT)
	{
		delete this->slots[index];
		this->slots[index] = materia;
	}
}

void Character::equip(AMateria* m)
{
	//cout << "Character::equip called" << endl;
    if (!m)
    {
        return ;
    }
	for (int i = 0; i < SLOT_COUNT; ++i)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			cout << this->name <<" equip <" << m->getType() << "> in slot " << i << endl;
			return;
		}
	}
    delete m;
	cout << "fail to equip... nothing happens"<< endl;
}

void Character::unequip(int idx)
{
    int remove_int;

    if (idx >= 0 && idx < SLOT_COUNT && slots[idx])
    {
        if (this->lost_count >= MAX_LOST - 1)
        {
            cout << "*****LOST_COUNT is " << this->lost_count<< " *********** should not see this" <<endl;
			remove_int = rand() % MAX_LOST;
            if (lostAndFound[remove_int])
            {
                delete lostAndFound[remove_int];
                lostAndFound[remove_int] = NULL;

            }
			cout << "Lost & Found full! Deleting random materia at index " << remove_int << endl;
			lostAndFound[remove_int] = slots[idx];
		}
        else
        {
			lostAndFound[this ->lost_count] = slots[idx];
            lost_count++;
        }

        cout << slots[idx]->getType() << " at slot " << idx << " is dropped to the lost and found..." << endl;
        slots[idx] = NULL;
    }
    else
        cout << "Nothing happens ... " << endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < SLOT_COUNT)
    {
        if (slots[idx] != NULL)
        {
            cout << this->name << " is using materia at slot "<< idx << " at " << target.getName() << endl;
            slots[idx]->use(target);
        }
        else
        {
            cout << this->name << " has no materia at slot " << idx << endl;
        }
    }
    else
        cout << "Nothing happens ... (idx out of range)" << endl;
}
