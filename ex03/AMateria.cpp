/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:47:18 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 14:49:59 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

AMateria::AMateria()
	:type("Default")
{
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria::AMateria(AMateria &other)
{
	*this = other;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria Constructor Called" << std::endl;
	this->type = type;
}

std::string const & AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}
