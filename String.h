/*
 * String.h
 *
 *  Created on: October 17, 2012
 *      Author: Todd Lunter
 *
 */

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include "Showable.h"

class MyString : public Showable
{
    public:
        MyString(const std::string& tmpStr) : str(tmpStr) {}
        virtual ~MyString(void) {}
        std::string Show(void) { return this->str; }

    private:
        std::string str;
};

#endif

