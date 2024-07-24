/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:38:42 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/24 09:30:22 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		~Animal();
		Animal(Animal &other);
		Animal	&operator=(const Animal &other);

		virtual void	makeSound() const;
		virtual std::string	getType() const;
};

#endif
