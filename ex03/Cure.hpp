/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:20:53 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 14:58:01 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(Cure &other);
		Cure	&operator=(const Cure &other);
		AMateria* clone() const;
		std::string const & getType() const;
		void use(ICharacter& target);
};

#endif
