/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:15:37 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 15:02:40 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Default Destructor Called" << std::endl;
}

Cure::Cure(Cure &other)
{
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure();
}

std::string const & Cure::getType() const
{
	return type;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() +"’s wounds *" << std::endl;
}
