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

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    ICharacter* bob = new Character("Bob");
    ICharacter* jim = new Character("Jim");

    bob->equip(ice);
    bob->equip(cure);
    bob->use(ice, *jim);
    bob->use(cure, *jim);

    delete bob;
    delete jim;
    delete ice;
    delete cure;

    return (0);
}
