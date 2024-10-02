/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:01 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/01 17:42:39 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

typedef std::string st;

void	BitcoinExchange(st file);

struct	checkTimeIfValid_st
{
	st	s_year;
	st	s_month;
	st	s_day;
	int	year;
	int	month;
	int	day;
};

#endif
