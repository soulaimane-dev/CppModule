/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:38:31 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/24 09:30:29 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog &other);
		Dog &operator=(const Dog &other);

		void	makeSound() const;
		std::string	getType() const;
};

#endif
