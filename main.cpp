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

int main(int argc, char** argv)
{
    MyString str("Test");
    Maybe<MyString> test(str);
    Maybe<MyString> test2;

    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
  
    return 0;
}

