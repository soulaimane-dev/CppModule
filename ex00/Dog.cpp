/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:38:34 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/24 09:31:06 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog::Dog(Dog &other)
{
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return  *this;
}


void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return this->type;
}
