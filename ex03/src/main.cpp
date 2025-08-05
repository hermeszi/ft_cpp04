/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
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

    std::cout << "=== Creating Materia Source and Learning ===\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    std::cout << "\n=== Creating Character 'me' and Equipping ===\n";
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

    std::cout << "\n=== Creating Character 'bob' and Using Materia ===\n";
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

    std::cout << "\n=== Re-equipping 'me' with another Cure ===\n";
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== Cleanup ===\n";
    delete bob;
    delete me;
    delete src;

    std::cout << "=== End of main ===\n";
    return 0;
}

