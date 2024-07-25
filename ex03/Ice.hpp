/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:20:18 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 14:58:06 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(Ice &other);
		Ice	&operator=(const Ice &other);
		AMateria* clone() const;
		std::string const & getType() const;
		void use(ICharacter& target);
};

#endif
