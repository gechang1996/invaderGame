/**
 * \file Item.h
 *
 * \author Chang Ge
 *
 * Base class to describe all items a part of the game
 */

#pragma once

#include <string>
#include <memory>
#include "ItemVisitor.h"

/**
 * Forward reference of game
 */
class CGame;

/**
 * Implement an Item class
 */
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	virtual ~CItem();
	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mPositionX; }

	bool HitTest2(int x, int y);

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mPositionY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mPositionX = x; mPositionY = y; }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics *graphics);

	/** Test this item to see if it has been clicked on
	 * \param x X location on the aquarium to test
	 * \param y Y location on the aquarium to test
	 * \return true if clicked on */
	virtual bool HitTest(int x, int y);

	void SetImage(const std::wstring &file);
	///  Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	virtual void LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) = 0;

	/** Set the speed of this item
	 * \param x X speed of the item
	 * \param y Y speed of the item 
	 */
	void SetSpeed(double x, double y) { mSpeedX = x; mSpeedY = y; }

	/** Getter for the x speed
	 * \returns double the x speed */
	double GetSpeedX() { return mSpeedX; }

	/** Getter for the y speed
	 * \returns double the y speed */
	double GetSpeedY() { return mSpeedY; }

	/** Getter for the game
	* \returns CGame */
	CGame* Getter() { return mGame; }
private:

	CGame   *mGame; ///< The game this item is contained in

	double mPositionX = 0; ///< x position of the item

	double mPositionY = 0; ///< y position of the item

	/// X speed of the item
	double mSpeedX = 0;

	/// Y speed of the item
	double mSpeedY = 0;
	/// Item image
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
protected:
	CItem(CGame *game);
	
};


