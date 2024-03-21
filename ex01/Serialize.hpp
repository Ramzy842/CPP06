/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:18:11 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/21 03:45:53 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include "./Data.hpp"
#include <iostream>
#include <limits>
#include <cctype>
#include <iomanip>

class Serialize
{
	private:
		Serialize();
		~Serialize();
		Serialize(const Serialize& original);
		Serialize& operator=(const Serialize& original);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif