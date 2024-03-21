/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:35:13 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/21 03:54:46 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serialize.hpp"

int main (int argc, char **argv)
{
	if (argc != 1 || argv[1])
	{
		std::cerr << "Usage: ./main" << std::endl;
		return (1);
	}
	Data *Data_ptr = new Data();
	Data_ptr->data = 25;
	uintptr_t ptr = Serialize::serialize(Data_ptr);
	Data *raw = Serialize::deserialize(ptr);
	std::cout << raw->data << std::endl;
	delete Data_ptr;
	return (0);
}