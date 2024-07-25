/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:38:59 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 15:02:26 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Ice Constructor Called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor Called" << std::endl;
}

Ice::Ice(Ice &other)
{
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice();
}


std::string const & Ice::getType() const
{
	return type;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() +" *" << std::endl;
}
