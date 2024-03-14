/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:15:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/14 01:44:31 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstring>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
	(void)original;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
	(void)original;
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	return *this;
}


// ---------------------------------------------------------------- CONVERT METHOD CODE ---------------------------------------------------------------- //

bool isSign(char c) {
  return c == '-' || c == '+';
}

size_t getSignCount(const std::string& str)
{
	size_t count = 0;
	for (size_t x = 0; x < str.length(); x++)
	{
		if (isSign(str[x]))
			count++;
	}
	return count;
}

bool allDigits(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool checkFloat(const std::string& str)
{
	std::string strTemp = str;
	if (getSignCount(strTemp) > 1)
		return false;
	bool beforeDotR_dig;
	if (getSignCount(strTemp) == 1)
		strTemp = &str[1];
	size_t dot_index = strTemp.find('.');
	if (dot_index) {
		if (strTemp[dot_index + 1] == 'f')
			return false;
		beforeDotR_dig = allDigits(strTemp.substr(0, dot_index));
		return beforeDotR_dig && allDigits(strTemp.substr(dot_index + 1, strTemp.length() - dot_index - 2)) && strTemp[strTemp.length() - 1] == 'f';
	}
	return false;
}

bool checkDouble(const std::string& str)
{
	std::string strTemp = str;
	if (getSignCount(strTemp) > 1)
		return false;
	bool beforeDotR_dig;
	if (getSignCount(strTemp) == 1)
		strTemp = &str[1];
	size_t dot_index = strTemp.find('.');
	if (dot_index) {
		beforeDotR_dig = allDigits(strTemp.substr(0, dot_index));
		return beforeDotR_dig && allDigits(strTemp.substr(dot_index + 1, strTemp.length() - dot_index - 1)) && strTemp[strTemp.length() - 1] != 'f';
	}
	return false;
}

bool checkInt(const std::string& str)
{
	std::string strTemp = str;
	if (getSignCount(strTemp) > 1)
		return false;
	if (getSignCount(strTemp) == 1)
		strTemp = &str[1];
	return allDigits(strTemp);
}


std::string ScalarConverter::convert(const std::string& str)
{
    bool isChar = str.size() == 1 && (isprint(str[0]) || str[0] == '\n' || str[0] == '\t') && !allDigits(str);
    bool isInt = checkInt(str);
    bool isFloat = checkFloat(str);
    bool isDouble = checkDouble(str);

	char charValue;
	int intValue;
	// float floatValue;
	// double doubleValue;
	if (isChar)
	{
		charValue = str[0];
		std::cout << "char: '" << str << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(charValue) << std::endl;
		std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
	}
	else if (isInt)
	{
		intValue = std::stoi(str);
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(intValue) << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
	}
	else if (isFloat)
		return "it's a float";
	else if (isDouble)
		return "it's a double";
	else if (str == "nan")
		return "it's a nan";
	return "";
}