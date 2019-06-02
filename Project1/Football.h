/**
 * \file Football.h
 *
 * \author Chang Ge
 *
 * Implementation of Football class
 */

#pragma once

#include <memory>
#include<vector>
#include "Item.h"

/**
 * Implement football class
 */
class CFootball : public CItem
{
public:
	CFootball() = delete; ///Default constructor (disabled)
	CFootball(const CFootball &) = delete; /// Copy constructor (disabled)
	virtual ~CFootball(); ///Destructor
	void Update(double elapsed);
	CFootball(CGame *game);
	///this function is called when a football hit a sparty or an invader
	void Shootsth();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitFootball(this); }
};