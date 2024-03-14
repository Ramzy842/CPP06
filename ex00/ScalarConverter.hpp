/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:13:37 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/14 01:20:34 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALER_CONVERTER
# define SCALER_CONVERTER

#include <iostream>
#include <limits>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		ScalarConverter& operator=(const ScalarConverter& original);
	public:
		static std::string convert(const std::string& str);
};

#endif