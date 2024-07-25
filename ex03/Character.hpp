/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:10:58 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/25 14:53:28 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		AMateria	*inventory[4];
		std::string	name;
	public:
		Character();
		Character(std::string name);
		Character(Character &other);
		Character &operator=(const Character &other);
		~Character();
		std::string	const & getName() const = 0;
		void 	equip(AMateria* m);
		void 	unequip(int idx);
		void 	use(int idx, ICharacter& target);
};

#endif
