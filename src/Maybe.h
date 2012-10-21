/*
 * Maybe.h
 *
 *  Created on: October 17, 2012
 *      Author: Todd Lunter
 *
 */

#ifndef _MAYBE_H_
#define _MAYBE_H_

#include <stdlib.h>
#include <sstream>
#include "Monad.h"
#include "Showable.h"

template <typename A>
class Maybe : public Monad<A>, public Showable
{
    public:
        Maybe(void) { val = NULL; }
        Maybe(A tmpVal) { val = new A(tmpVal); }
        ~Maybe() { delete val; }
        A FromJust()
        {
            if (val == NULL)
            {
                //throw Error();
            }
            else
            {
                return *val;
            }
        }

        bool IsJust()
        {
            return (val != NULL);
        }

        bool IsNothing()
        {
            return (val == NULL);
        }

        template <typename Func, typename B>
        Maybe<B> Bind(Func func)
        {
            if (val)
                return func(*val);
            else
                return Maybe<B>();
        }
        static Maybe<A> Inject(A tmpVal) { return Maybe<A>(tmpVal); }

        std::string Show(void)
        {
            if (val == NULL)
                return "Nothing";

            std::stringstream stream;
            stream << "Just " << val->Show();
            return stream.str();
        }

    private:
        A* val;
};

#endif

