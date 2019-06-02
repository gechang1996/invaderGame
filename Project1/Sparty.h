/**
 * \file Sparty.h
 *
 * \author Chang Ge
 *
 * Declares the Sparty item in the game
 */

#pragma once

#include "Item.h"

 /**
  * Sparty class derived class of CItem
  */
class CSparty : public CItem
{
public:
	/// Constructor delete
	CSparty() = delete;
	
	/// Copy constructor (disabled)
	CSparty(const CSparty &) = delete;
	
	///Desctructor
	virtual ~CSparty();
	
	/**
	 * Constructor 
	 * \param game Game we are passing in */
	CSparty(CGame *game);
	
	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitSparty(this); }

private:
	/// Image
	std::unique_ptr<Gdiplus::Bitmap>mSpartyImage;
};

