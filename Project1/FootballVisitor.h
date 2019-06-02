/**
 * \file FootballVisitor.h
 *
 * \author Chang Ge
 *
 * Class for visiting the footballs
 */

#pragma once

#include "ItemVisitor.h"

/**
 * implement a new football visitor and calls shootsth when football hits
 */
class CFootballVisitor:public CItemVisitor
{
public:
	CFootballVisitor();
	virtual ~CFootballVisitor();
	/**
	* Function for visiting football
	* \param football used for being visited
	*/
	virtual void VisitFootball(CFootball *football) override;
};