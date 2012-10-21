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
#include "List.h"

int main(int argc, char** argv)
{
    /*
    String str("Test");
    Maybe<String> test(str);
    Maybe<String> test2;
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;

	Natural zero;
	Natural one(zero);
	std::cout << zero << " " << zero.FromEnum() << std::endl;
	std::cout << one << " " << one.FromEnum() << std::endl;
	one.Succ();
	std::cout << one << " " << one.FromEnum() << std::endl;
	one.Pred();
	std::cout << one << " " << one.FromEnum() << std::endl;
	one.Pred();
	std::cout << one << " " << one.FromEnum() << std::endl;
	one.Pred();
	std::cout << one << " " << one.FromEnum() << std::endl;
    */
    String str1("hey");
	String str2("there");
	String str3("jim");
	List<String> list(str1, List<String>(str2, List<String>(str3)));
	std::cout << list << std::endl;
	str1 = list[2];
	std::cout << str1 << std::endl;
	List<String> list2 = list.reverse();
	std::cout << list2 << std::endl; 

    list2.appendD(list);
	std::cout << list2 << std::endl; 
    std::cout << list  << std::endl;

    return 0;
}

