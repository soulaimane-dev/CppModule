/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:33:59 by sbouabid          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/25 16:04:27 by sbouabid         ###   ########.fr       */
=======
/*   Updated: 2024/07/25 16:04:47 by sbouabid         ###   ########.fr       */
>>>>>>> f6b9f87136cfa2f5e0ff5dadd2c256f6b36dcaac
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class	Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat &other);
		Cat &operator=(const Cat &other);
		void	makeSound() const;
		std::string getType() const;
};

#endif
