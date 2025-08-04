/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string			type;

public:
	// Constructors and Destructor
	WrongAnimal();
	WrongAnimal(std::string name);
	~WrongAnimal();
	WrongAnimal	(const WrongAnimal& copy);

	// Assignment operator
	WrongAnimal&	operator= (const WrongAnimal& other);

	// Getters and Setters
	std::string	getType() const;
	void	    setType(std::string type);

	// Member functions
	void	makeSound() const;
};

#endif
