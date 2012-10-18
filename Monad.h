/*
 * Monad.h
 *
 *  Created on: October 17, 2012
 *      Author: Todd Lunter
 *
 */

#ifndef _MONAD_H_
#define _MONAD_H_

#include <exception>

class NotImplementedError : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Can't operate on Monad typeclass";
        }
};

template <typename A>
class Monad
{
    public:
        template <typename Func, typename B>
        Monad<B> Bind(Func func) { throw NotImplementedError(); }

        static Monad<A> Inject(A val) { throw NotImplementedError(); }
};

#endif

