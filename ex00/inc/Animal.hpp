/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string			type;

public:
	// Constructors and Destructor
	Animal();
	Animal(std::string type);
	virtual ~Animal();
	Animal	(const Animal& copy);

	// Assignment operator
	Animal&	operator= (const Animal& other);
	
	// Getters and Setters
	std::string	getType() const;
	void	    setType(std::string type);

	// Member functions
	virtual void	makeSound() const;
};

#endif
