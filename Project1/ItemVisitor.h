/**
 * \file ItemVisitor.h
 *
 * \author Chang Ge
 *
 * Abstract base class for all our visitors
 */

#pragma once

class CBunker;
class CInvader;
class CSparty;
class CFootball;


/**
 * visitor class to visit items and see if they get hit
 */
class CItemVisitor
{
public:
	CItemVisitor();
	virtual ~CItemVisitor();

	/** Visit an invader object
	 * \param invader Invader we are visiting */
	virtual void VisitInvader(CInvader *invader) {}
	
	/** Visit a bunker object
	 * \param bunker Bunker we are visiting */
	virtual void VisitBunker(CBunker *bunker) {}
	
	/** Visit a Sparty object
	 * \param sparty Bunker we are visiting */
	virtual void VisitSparty(CSparty *sparty) {}
	
	/** Visit a football object
	 * \param football Bunker we are visiting */
	virtual void VisitFootball(CFootball *football) {}
};

