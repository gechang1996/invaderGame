/**
 * \file InvaderWisconsin.h
 *
 * \author Chang Ge
 *
 * Class that describes the Wisconsin type invaders
 */

#pragma once

#include "Invader.h"
#include "InvaderVisitor.h"

/**
 * Implment invader Wisconsin
 */
class CInvaderWisconsin :
	public CInvader
{
public:
	CInvaderWisconsin::CInvaderWisconsin(CGame *game);

	virtual ~CInvaderWisconsin();

	/// Default constructor (disabled)
	CInvaderWisconsin() = delete;


	/**  Draw this item
	* \param graphics The graphics context to draw on */
	void Draw(Gdiplus::Graphics *graphics);

	/// Copy constructor (disabled)
	CInvaderWisconsin(const CInvaderWisconsin &) = delete;
	void Update(double elapsed);

	///** Accept a visitor
	// * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor)override{ visitor->VisitInvader(this); }
	
private:
	/// Third wisonsin image
	std::unique_ptr<Gdiplus::Bitmap> mImage8;
};

