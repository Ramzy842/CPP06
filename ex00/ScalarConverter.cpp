/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:15:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/14 16:49:45 by rchahban         ###   ########.fr       */
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

void printTypes(bool isChar, bool isInt, bool isFloat, bool isDouble)
{
	std::cout << "char: " << isChar << std::endl;
	std::cout << "int: " << isInt << std::endl;
	std::cout << "float: " << isFloat << std::endl;
	std::cout << "double: " << isDouble << std::endl;
}

std::string ScalarConverter::convert(const std::string& str)
{
    bool isChar = str.size() == 1 && (isprint(str[0]) || str[0] == '\n' || str[0] == '\t') && !allDigits(str);
    bool isInt = checkInt(str);
    bool isFloat = checkFloat(str);
    bool isDouble = checkDouble(str);

	char charValue = '\0';
	int intValue = 0;
	float floatValue = 0;
	double doubleValue = 0;
	printTypes(isChar, isInt, isFloat, isDouble);
	bool err = false;
	if (!isChar && !isInt && !isFloat && !isDouble)
		err = true;
	if (str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else if (isChar)
	{
		charValue = str[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
	}
	else if (isInt)
	{
		try {
			intValue = std::stoi(str);
			floatValue = static_cast<float>(intValue);
			doubleValue = static_cast<double>(intValue);
		}
		catch (std::out_of_range& e){
			err = true;
		}
	}
	else if (isFloat)
	{
		try {
			floatValue = std::stof(str);
			charValue = static_cast<char>(floatValue);
			intValue = static_cast<int>(floatValue);
			doubleValue = static_cast<double>(floatValue);
		}
		catch (std::out_of_range& e)
		{
			err = true;
		}
	}	
	else if (isDouble)
	{
		try {
			doubleValue = std::stod(str);
			floatValue = static_cast<float>(doubleValue);
			charValue = static_cast<char>(doubleValue);
			intValue = static_cast<int>(doubleValue);
		}
		catch (std::out_of_range& e)
		{
			err = true;
		}
	}
	if (err)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
	}
	else {
		if (charValue)
			std::cout << "char: '" << charValue << "'" << std::endl;
		else if (!charValue)
			std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << floatValue << ".0f" << std::endl;
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	}
	return "";
}