/**
 * \file InvaderIowa.h
 *
 * \author Chang Ge
 *
 * Class that describes the Iowa type invaders
 */

#pragma once

#include "Invader.h"
#include "InvaderVisitor.h"

/**
 * Implement invader Iowa
 */
class CInvaderIowa :
	public CInvader
{
public:
	CInvaderIowa::CInvaderIowa(CGame *game);

	virtual ~CInvaderIowa();

	/// Default constructor (disabled)
	CInvaderIowa() = delete;

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	void Draw(Gdiplus::Graphics *graphics);

	/// Copy constructor (disabled)
	CInvaderIowa(const CInvaderIowa &) = delete;
	void Update(double elapsed);
	
	/** Accept a visitor
	  * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitInvader(this); }
};

