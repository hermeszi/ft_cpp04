/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string		type;

public:
	// Constructors and Destructor
	AAnimal();
	AAnimal(std::string name);
	virtual ~AAnimal();
	AAnimal	(const AAnimal& copy);

	// Assignment operator
	AAnimal&	operator= (const AAnimal& other);
	
	// Getters and Setters
	std::string	getType() const;
	void	    setType(std::string type);

	// Member functions
	virtual void	makeSound() const = 0; // Pure virtual function, making AAnimal an abstract class
};

#endif
