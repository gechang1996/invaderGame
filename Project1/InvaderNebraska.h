/**
 * \file InvaderNebraska.h
 *
 * \author Chang Ge
 *
 * Class that describes the Nebraska type invaders
 */

#pragma once

#include "Invader.h"
#include "InvaderVisitor.h"

/**
 * Implement invader Nebraska
 */
class CInvaderNebraska :
	public CInvader
{
public:
	CInvaderNebraska::CInvaderNebraska(CGame *game);

	virtual ~CInvaderNebraska();

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	void Draw(Gdiplus::Graphics *graphics);

	/// Default constructor (disabled)
	CInvaderNebraska() = delete;

	/// Copy constructor (disabled)
	CInvaderNebraska(const CInvaderNebraska &) = delete;
	void Update(double elapsed);

	///** Accept a visitor
	// * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor)override { visitor->VisitInvader(this); }
	
private:
	/// The distance of the invader
	double mDistance = 0;
	/// Angle of the invader
	double mAngle = 0;
};




