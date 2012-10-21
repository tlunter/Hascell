/* This class is for passing around multiple values of different types. It has
 * only two functions, first and second, which returns those respecitve values
 * in the tuple.
 *
 * Created on October 21, 2011
 * Author: Tom Hulihan
 **/
#ifndef _TUPLE_H_
#define _TUPLE_H_

#include <sstream>
#include "Showable.h"

template <typename A, typename B>
class Tuple : public Showable
{
    public:

        Tuple() : fst(A()), snd(B()) {}
        Tuple(A f, B s) : fst(f), snd(s) {}
        Tuple(const Tuple& t) : fst(t.fst), snd(t.snd) {}

        A first()
        {
            return fst;
        }

        B second()
        {
            return snd;
        }
        
        std::string Show()
        {
            std::ostringstream os;
            os << '(' << fst << ',' << snd << ')';
            return os.str();
        }

    private:
        A fst;
        B snd;
    
};

#endif
