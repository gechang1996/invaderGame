/**
 * \file Invader.h
 *
 * \author Chang Ge
 *
 * Class that describes a general invader
 */

#pragma once

#include "Item.h"

/**
 * Implement invader class
 */
class CInvader : public CItem
{
public:
	CInvader(CGame *game);

	CInvader() = delete; /// Default constructor (disabled)
	CInvader(const CInvader &) = delete; /// Copy constructor (disabled)
	virtual ~CInvader(); /// Default destructor
	virtual void Update(double elapsed);

	/** Set the location of the invader
	 * \param x The x location to set
	 * \param y The y location to set 
	 */
	void SetLocation(double x, double y);

	/** Delete an invader from a location
	 * \param x The x location to delete from
	 * \param y The y location to delete from 
	 */
	void DeleteInvader(double x, double y);
	void MSUPlusOne();
	void SetShoot();
	void Draw(Gdiplus::Graphics * graphics);
	/** Returns if an invader is shot
	 * \returns flag for if invader shot
	 */
	double GetShoot() {return mIsShot;}
	void Step();
	/** Get the flag of the invader
	 * \returns the invader flag 
	 */
	int GetFlag() { return mFlag; }
	
	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitInvader(this); }

private:
	/// Football image
	std::unique_ptr<Gdiplus::Bitmap> mFootballImage;

	double mCountLine; ///< The number of steps taken on a line
	double mCountMove = 0; ///< deicde when to move down and move back

	double mSpeed = 0.5; ///< step speed
	double mXMove = 10; ///< The step length

	int mFlag = 1; ///< flags if the invader should be in state 1 or 0 of their step

	double mIsShot = 0; ///< reflects if the invader has been shot

protected:
	/// How much we offset drawing the tile to the left of the center
	const int mOffsetLeft = 64;
	/// How much we offset drawing the tile above the center
	const int mOffsetDown = 32;
	/// Invader's fist step image
	std::unique_ptr<Gdiplus::Bitmap> mImage1;
	/// Invader's second step image
	std::unique_ptr<Gdiplus::Bitmap> mImage2;
	/// Timer 1
	double mTimer = 0;
};

