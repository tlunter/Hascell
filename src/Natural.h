/*
 * Natural.h
 *
 *  Created on: October 18, 2012
 *		Author: Todd Lunter
 *
 */

#ifndef _NATURAL_H_
#define _NATURAL_H_

#include <stdlib.h>
#include <sstream>
#include "Enum.h"
#include "Showable.h"
#include "Maybe.h"

class Natural : public Enum, public Showable
{
	public:
		Natural(void) { val = NULL; }
		Natural(Natural& tmpVal) { val = &tmpVal; }
        ~Natural(void) { delete val; }

		void Succ(void);
		void Pred(void);
		int FromEnum(void);

		std::string Show(void);

	private:
		Natural* val;
};

#endif

