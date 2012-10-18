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
    String str("Test");
    Maybe<String> test(str);
    Maybe<String> test2;

    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
  
    return 0;
}

