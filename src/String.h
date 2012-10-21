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

class String : public Showable
{
    public:
        String() : str("") {}
        String(const std::string& tmpStr) : str(tmpStr) {}
        virtual ~String(void) {}
        std::string Show(void) { return this->str; }
        int Length(void) { return this->str.length(); }

    private:
        std::string str;
};

#endif

