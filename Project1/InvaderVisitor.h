/**
 * \file InvaderVisitor.h
 *
 * \author Chang Ge
 *
 * Abstract base class for our invader visitors
 */
#include "ItemVisitor.h"

#pragma once

// Forward refrences to all invader types
class CInvaderIowa;
class CInvaderMichigan;
class CInvaderNebraska;
class CInvaderOhioState;
class CInvaderWisconsin;


/**
 * abstract base class for our visitors
 */
class CInvaderVisitor: public CItemVisitor
{
public:
	CInvaderVisitor();
	virtual ~CInvaderVisitor();

	/** Visit a CInvaderIowa object
	 * \param iowa Invader we are visiting */
	virtual void VisitIowa(CInvaderIowa *iowa) {}

	/** Visit a CInvaderMichigan object
	 * \param michigan Invader we are visiting */
	virtual void VisitMichigan(CInvaderMichigan *michigan) {}
	
	/** Visit a CInvaderNebraska object
	 * \param nebraska Invader we are visiting */
	virtual void VisitNebraska(CInvaderNebraska *nebraska) {}

	/** Visit a CInvaderOhioState object
	 * \param ohio Invader we are visiting */
	virtual void VisitOhioState(CInvaderOhioState *ohio) {}

	/** Visit a CInvaderWisconsin object
	 * \param wisconsin Invader we are visiting */
	virtual void VisitWisconsin(CInvaderWisconsin *wisconsin) {}

	/**
	 * Function for visiting invader
	 * \param invader used for being visited
	 */
	virtual void VisitInvader(CInvader *invader) override;

};

