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
