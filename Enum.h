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
        virtual void Succ(void) { throw NotImplementedError(); }
        virtual void Pred(void) { throw NotImplementedError(); }
        virtual int FromEnum(void) { throw NotImplementedError(); }
};

#endif

