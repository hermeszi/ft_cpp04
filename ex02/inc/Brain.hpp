/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string			ideas[100];

public:
	// Constructors and Destructor
	Brain();
	~Brain();
	Brain	(const Brain& copy);

	// Assignment operator
	Brain&	operator= (const Brain& other);
	
	// Getters and Setters
	const std::string&	getIdeas(int index) const;
    void setIdeas(int index, const std::string& idea);

};

#endif
