/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define SLOT_COUNT 4
#define	MAX_LOST 20

class AMateria;

class Character : public ICharacter
{
private:
	std::string		name;
	AMateria*		slots[SLOT_COUNT];
	AMateria*		lostAndFound[MAX_LOST];
	int				lost_count;

public:
	// Constructors and Destructor
	Character();
	Character(std::string name);
	Character	(const Character& copy);
	~Character();
	
    // Assignment operator
	Character& operator= (const Character& other);

    // Getters and Setters
	const std::string& getName() const;
	const int& getLostCount() const;
    AMateria* getMateria(int index) const; // cannot be const pointer
	AMateria* getLostFound(int index) const;
    void setMateria(int index, AMateria* materia);

	// Member Functions 
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
