/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define SLOT_COUNT 4
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
class AMateria;

class MateriaSource : public IMateriaSource
{
private:
    AMateria* slots[SLOT_COUNT];

public:
	// Constructors and Destructor
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    ~MateriaSource();

    // Assignment operator
    MateriaSource& operator=(const MateriaSource& other);

    // Getters and Setters
    AMateria* getMateria(int index) const; // cannot be const pointer
    void setMateria(int index, AMateria* materia);

    // Member functions
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
