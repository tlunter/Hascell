/*
 * main.cpp
 *
 *  Created on: October 17, 2012
 *      Author: Todd Lunter
 *
 */

#include <iostream>
#include "String.h"
#include "Maybe.h"
#include "Natural.h"

int main(int argc, char** argv)
{
    String str("Test");
    Maybe<String> test(str);
    Maybe<String> test2;
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;

	Natural zero;
	Natural one(zero);
	std::cout << zero.FromEnum() << std::endl;
	std::cout << one.FromEnum() << std::endl;
	one.Succ();
	std::cout << one.FromEnum() << std::endl;
	one.Pred();
	std::cout << one.FromEnum() << std::endl;
	one.Pred();
	std::cout << one.FromEnum() << std::endl;
	one.Pred();
	std::cout << one.FromEnum() << std::endl;

    return 0;
}

