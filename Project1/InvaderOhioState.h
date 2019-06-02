/**
 * \file InvaderOhioState.h
 *
 * \author Chang Ge
 *
 * Class that describes the Ohio State type invaders
 */

#pragma once

#include "Invader.h"
#include "InvaderVisitor.h"

/**
 * Implement invader OhioState
 */
class CInvaderOhioState :
	public CInvader
{
public:
	CInvaderOhioState::CInvaderOhioState(CGame *game);

	virtual ~CInvaderOhioState();

	/// Default constructor (disabled)
	CInvaderOhioState() = delete;

	/// Copy constructor (disabled)
	CInvaderOhioState(const CInvaderOhioState &) = delete;
	void Update(double elapsed);

	void Draw(Gdiplus::Graphics *graphics);

	///** Accept a visitor
	// * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor)override { visitor->VisitInvader(this); }
};

