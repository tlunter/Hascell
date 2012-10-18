/*
 * Enum.h
 *
 *  Created on: October 18, 2012
 *      Author: Todd Lunter
 *
 */

#ifndef _ENUM_H_
#define _ENUM_H_

#include "Exceptions.h"

class Enum
{
    public:
        virtual Enum Succ(void) { throw NotImplementedError(); }
        virtual Enum Pred(void) { throw NotImplementedError(); }
};

#endif

