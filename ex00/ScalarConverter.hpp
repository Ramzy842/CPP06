/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:13:37 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/21 03:13:30 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALER_CONVERTER_HPP
# define SCALER_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		ScalarConverter& operator=(const ScalarConverter& original);
		static int intValue;
		static float floatValue;
		static double doubleValue;
		static char charValue;
	public:
		static void convert(const std::string& str);
};

#endif