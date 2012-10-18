/*
 * Natural.h
 *
 *  Created on: October 18, 2012
 *		Author: Todd Lunter
 *
 */

#include "Natural.h"

void Natural::Succ(void)
{
	val = new Natural(*val);
}

void Natural::Pred(void)
{
	if (val != NULL)
		val = val->val;
}

int Natural::FromEnum(void)
{
	return (val == NULL) ? 0 : 1 + val->FromEnum();
}

std::string Natural::Show(void)
{
	std::stringstream string;
	if (val == NULL)
		string << "(0)";
	else
		string << "(+ 1 " << val->Show() << ")";
	return string.str();
}

