#include "List.h"
#include "Showable.h"
#include "String.h"
#include <iostream>


int main()
{
    String str("hey");
    String str2("there");
    String str3("jim");
    List<String> list(str, List<String>(str2, List<String>(str3)));
    std::cout << list << std::endl;
    str = list[2];
    std::cout << str << std::endl   ;
    return 0;
}
