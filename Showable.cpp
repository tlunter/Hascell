/*
 * Showable.cpp
 *
 *  Created on: October 17, 2012
 *      Author: Todd Lunter
 *
 */

#include "Showable.h"

std::ostream& operator<< (std::ostream& out, Showable& show)
{
    out << show.Show();
    return out;
}

