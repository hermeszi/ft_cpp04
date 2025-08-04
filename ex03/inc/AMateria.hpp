/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
class ICharacter;

class AMateria
{
protected:
	std::string		type;

public:
	// Constructors and Destructor
	AMateria();
	AMateria(std::string name);
	virtual ~AMateria();
	AMateria	(const AMateria& copy);

	// Assignment operator
	AMateria&			operator= (const AMateria& other);
	
	// Getters and Setters
	const std::string& 	getType() const;
	void	    		setType(std::string type);

	// Member functions
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
