/**
 * \file InvaderCounter.h
 *
 * \author Chang Ge
 *
 * Class that uses CInvaderVisitor base class to create concrete visitors to count the invaders
 */

#pragma once

#include "ItemVisitor.h"


/**
 * Visitor class to count the number of invaders
 */
class CInvaderCounter :
	public CItemVisitor
{
public:
	CInvaderCounter();
	virtual ~CInvaderCounter();

	
	void VisitInvader(CInvader *invader);

	/** Getter for number of invaders
     * \return Number of fans */
	int GetNumInvaders() const { return mNumInvaders; }

private:
	///Invader Counter
	int mNumInvaders = 0;
};

