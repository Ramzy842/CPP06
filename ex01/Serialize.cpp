/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:12:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/21 03:37:49 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize()
{
}
Serialize::~Serialize()
{	
}
Serialize::Serialize(const Serialize& original)
{
	*this = original;
}
Serialize& Serialize::operator=(const Serialize& original)
{
	(void)original;
	return (*this);
}

uintptr_t Serialize::serialize(Data* ptr)
{
	uintptr_t value = reinterpret_cast<uintptr_t>(static_cast<void*>(ptr));
	return value;
}
Data* Serialize::deserialize(uintptr_t raw)
{
	Data* data = reinterpret_cast<Data*>(raw);
	return data;
}