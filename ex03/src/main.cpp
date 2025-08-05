/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/05 18:45:27 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "=== Creating Materia Source and Learning ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    std::cout << "\n=== Creating Character 'me' and Equipping ===" << std::endl;
    ICharacter* me = new Character("Player");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("kamehameha");
    me->equip (tmp);
    tmp = src->createMateria("ice");
    me->equip (tmp);
    tmp = src->createMateria("ice");
    me->equip (tmp);
    tmp = src->createMateria("ice");
    me->equip (tmp);

    std::cout << "\n=== Creating Character 'bob' and Using Materia ===" << std::endl;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(5, *bob);

    std::cout << "\n=== Unequipping slot 0 from 'me' ===\n";
    me->unequip(0);
    me->unequip(2);
    me->unequip(1);
    me->unequip(5);

    std::cout << "\n=== Re-equipping 'me' with another Cure ===" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== Deep Copy Test  ===" << std::endl;
    Character* shadow = new Character("shadow");
    shadow->equip(new Ice());
    Character copyOfShadow = *shadow;
    shadow->unequip(0);
    copyOfShadow.use(0, *bob);

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete shadow;

    std::cout << "=== End of main ===" << std::endl;
    
    return (0);
}

