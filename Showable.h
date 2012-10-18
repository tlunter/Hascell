/*
 * Showable.h
 *
 *  Created on: October 17, 2012
 *      Author: Todd Lunter
 *
 */

#ifndef _SHOWABLE_H_
#define _SHOWABLE_H_

#include <iostream>
#include "Exceptions.h"

class Showable
{
    public:
        Showable(void) {}
        virtual ~Showable(void) {}
        virtual std::string Show(void) { throw ShowException(); }
        friend std::ostream& operator<< (std::ostream& out, Showable& show);
};

#endif

