/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:35:13 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/15 23:30:39 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2 || argv[2])
	{
		std::cerr << "Usage: ./convert arg" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}