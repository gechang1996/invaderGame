/**
 * \file InvaderMichigan.h
 *
 * \author Chang Ge
 *
 * Class that describes the Michigan type invaders
 */

#pragma once

#include "Invader.h"
#include "InvaderVisitor.h"

/**
 * Implement invader Michigan
 */
class CInvaderMichigan :
	public CInvader
{
public:
	CInvaderMichigan::CInvaderMichigan(CGame *game);

	virtual ~CInvaderMichigan();

	/// Default constructor (disabled)
	CInvaderMichigan() = delete;

	/// Copy constructor (disabled)
	CInvaderMichigan(const CInvaderMichigan &) = delete;
	void Update(double elapsed);

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	void Draw(Gdiplus::Graphics *graphics);

	///** Accept a visitor
	// * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor)override { visitor->VisitInvader(this); }
private:
	/// Timer 2
	double mTimer2=0;
	/// Image 15
	std::unique_ptr<Gdiplus::Bitmap> mImage15;
	/// Image 16
	std::unique_ptr<Gdiplus::Bitmap> mImage16;
};

