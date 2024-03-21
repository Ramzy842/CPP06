/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:15:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/21 00:59:09 by rchahban         ###   ########.fr       */
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

int ScalarConverter::intValue = 0;
double ScalarConverter::doubleValue = 0.0;
float ScalarConverter::floatValue = 0.0f;
char ScalarConverter::charValue = '\0';

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
	if (dot_index == std::string::npos)
		return false;
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
	if (dot_index == std::string::npos)
		return false;
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

void handleInt(char *cstr, int& intValue, float& floatValue, double& doubleValue, char& charValue)
{
	intValue = atoi(cstr);
	charValue = static_cast<char>(intValue);
	floatValue = static_cast<float>(std::strtof((cstr), NULL));
	doubleValue = static_cast<double>(std::strtod((cstr), NULL));
	if (intValue < 32 || intValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	if (std::strtod((cstr), NULL) > 2147483647.0 || std::strtod((cstr), NULL) < -2147483648.0)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
		std::cout << "int: " << intValue << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
}


void handleFloat(char *cstr, int& intValue, float& floatValue, double& doubleValue, char& charValue)
{
	floatValue = std::strtof(cstr, NULL);
	charValue = static_cast<char>(floatValue);
	intValue = static_cast<int>(floatValue);
	doubleValue = static_cast<double>(floatValue);
	if (charValue < 32 || charValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	// INT
	if (std::strtod(cstr, NULL) > 2147483647.0 || std::strtod(cstr, NULL) < -2147483648.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;
	// FLOAT
	std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
	// DOUBLE
	std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
}
void handleChar(const std::string& str, char& charValue, int& intValue, float& floatValue, double& doubleValue)
{
	charValue = str[0];
	intValue = static_cast<int>(charValue);
	floatValue = static_cast<float>(charValue);
	doubleValue = static_cast<double>(charValue);
	if (charValue < 32 || charValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	// INT
	std::cout << "int: " << intValue << std::endl;
	// FLOAT
	std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
	// DOUBLE
	std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
	
}

void handleDouble(char *cstr, int& intValue, float& floatValue, double& doubleValue, char& charValue)
{
	doubleValue = std::strtod(cstr, NULL);;
	floatValue = static_cast<float>(doubleValue);
	charValue = static_cast<char>(doubleValue);
	intValue = static_cast<int>(doubleValue);
	if (charValue < 32 || charValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	// INT
	if (doubleValue > 2147483647.0 || doubleValue < -2147483648.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;
	// FLOAT
	std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
	// DOUBLE
	std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
}

void handleNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
}

void handleMinusInf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "-inff" << std::endl;
	std::cout << "double: " << "-inf" << std::endl;
}

void handlePlusInf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "+inff" << std::endl;
	std::cout << "double: " << "+inf" << std::endl;
}

void handleUnknownStr()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    bool isChar = str.size() == 1 && (isprint(str[0]) || str[0] == '\n' || str[0] == '\t') && !allDigits(str);
    bool isInt = checkInt(str);
    bool isFloat = checkFloat(str);
    bool isDouble = checkDouble(str);

	char *cstr = new char [str.length()+1];
	strcpy (cstr, str.c_str());
	if (!str.size())
	{
		handleUnknownStr();
		return ;
	}
	if (!isChar && !isInt && !isFloat && !isDouble)
	{
		handleUnknownStr();
		return ;
	}
	if (str == "nan" || str == "nanf")
	{
		handleNan();
		return ;
	}
	if (str == "+inf" || str == "+inff")
	{
		handlePlusInf();
		return ;
	}
	if (str == "-inf" || str == "-inff")
	{
		handleMinusInf();
		return ;
	}
	else if (isChar)
		handleChar(str, charValue, intValue, floatValue, doubleValue);
	else if (isInt)
		handleInt(cstr, intValue, floatValue, doubleValue, charValue);
	else if (isFloat)
		handleFloat(cstr, intValue, floatValue, doubleValue, charValue);
	else if (isDouble)
		handleDouble(cstr, intValue, floatValue, doubleValue, charValue);
}