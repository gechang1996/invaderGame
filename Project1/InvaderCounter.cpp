/**
 * \file InvaderCounter.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include "InvaderCounter.h"

 /**
 * Constructor
 */
CInvaderCounter::CInvaderCounter()
{
}

/**
* Deconstructor
*/
CInvaderCounter::~CInvaderCounter()
{
}

/** Visit a CInvader object
* \param invader Invader we are visiting */
void CInvaderCounter::VisitInvader(CInvader *invader)
{
	mNumInvaders++;
}