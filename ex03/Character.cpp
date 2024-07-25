/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:05:01 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 15:13:54 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	this->name = "Default";
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
	std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
	std::cout << "Character Constructor Called" << std::endl;
}

Character::Character(Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
	this->name = other.name;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
		this->name = other.name;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != nullptr)
		{
			inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		inventory[idx] = nullptr;
	}
}

std::string	const &Character::getName() const
{
	return name;
}


void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx]->use(target);
	else
		std::cout << "materia index: " << idx << " is empty" << std::endl;
}
