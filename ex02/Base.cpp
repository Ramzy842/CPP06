/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 03:03:16 by rchahban          #+#    #+#             */
/*   Updated: 2024/03/23 08:55:04 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{
	
}

Base* Base::generate()
{
	Base* instance = NULL;

	srand(time(NULL));
	int random_num = rand() % 3;
	switch (random_num)
	{
	case 0:
		instance = new A();
		std::cout << "Instantiated A" << std::endl;
		break;
	case 1:
		instance = new B();
		std::cout << "Instantiated B" << std::endl;
		break;
	default:
		instance = new C();
		std::cout << "Instantiated C" << std::endl;
		break;
	}
	return instance; 
}

void Base::identify(Base* p)
{
	Base *d1 = dynamic_cast<A*>(p);
	Base *d2 = dynamic_cast<B*>(p);
	Base *d3 = dynamic_cast<C*>(p);
	std::cout << ">>>>>>>>>>>>> Pointer identification <<<<<<<<<<<<<" << std::endl;
	if (d1)
		std::cout << "Type of object identified: A" << std::endl;
	else if (d2)
		std::cout << "Type of object identified: B" << std::endl;
	else if (d3)
		std::cout << "Type of object identified: C" << std::endl;
}

void Base::identify(Base& p)
{
	std::cout << ">>>>>>>>>>>>> Reference identification <<<<<<<<<<<<<" << std::endl;
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type of object identified: A" << std::endl;
	}
	catch (std::exception& bad_cast )
	{
		(void) bad_cast;
		// std::cout << bad_cast.what() << std::endl;
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type of object identified: B" << std::endl;
	}
	catch (std::exception& bad_cast )
	{
		(void) bad_cast;
		// std::cout << bad_cast.what() << std::endl;
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type of object identified: C" << std::endl;
	}
	catch (std::exception& bad_cast )
	{
		(void) bad_cast;
		// std::cout << bad_cast.what() << std::endl;
	}
}