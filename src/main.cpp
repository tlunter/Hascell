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

List<int> quickSort(List<int> xs)
{
    if(xs.isEmpty())
        return List<int>();
    int piv = xs.restD();
    auto isLessThan    = [piv](int y) -> bool { return y <  piv; };
    auto isGreaterThan = [piv](int y) -> bool { return y >= piv; };
    return xs.filter(&isLessThan).append(List<int>(piv, xs.filter(&isGreaterThan)));
}

void printInt(int x)
{
    std::cout << x << " ";
}

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

    List<int> xs(2, List<int>(3, List<int>(1)));
    std::cout << xs << std::endl;
    List<int> ys = quickSort(xs);
    std::cout << ys << std::endl;

    return 0;
}
