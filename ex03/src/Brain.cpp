/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using std::string;
using std::endl;
using std::cout;

Brain::Brain() 
{
	cout << "Brain default constructor called" <<endl;
	for (int i = SLOT_COUNT; i < 100; ++i)
    	ideas[i] = "empty dreams";
}

Brain::Brain	(const Brain& copy)
{
	cout << "Brain Copy constructor called" << endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = copy.getIdeas(i);
}

Brain& Brain::operator= (const Brain& other)
{
	cout << "Brain Copy Assignment operator called" << endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.getIdeas(i);
		}
	}
	return (*this);
}

Brain::~Brain()
{
	cout << "Brain destructor called" << endl;
}

const string&	Brain::getIdeas(int index) const
{
	return (this->ideas[index]);
}

void Brain::setIdeas(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}
