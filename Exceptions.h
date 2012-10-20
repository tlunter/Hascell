/*
 * Exceptions.h
 *
 *  Created on: October 18, 2012
 *      Author: Todd Lunter
 *
 */

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>

class NotImplementedError : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Can't operate on Monad typeclass";
        }
};

class ShowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Can't show Show typeclass";
        }
};

#endif

