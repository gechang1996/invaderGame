/**
 * \file Bunker.h
 *
 * \Chang Ge
 *
 * implement bunker class
 */

#pragma once
#include <memory>
#include "Item.h"


/**
 * bunker class to protect sparty from invader footballs
 */
class CBunker : public CItem
{
public:
	CBunker() = delete; ///< default constructor (disabled)
	CBunker(const CBunker &) = delete; ///< Copy constructor (disabled)
	virtual ~CBunker();
	CBunker(CGame *game);
	void Draw(Gdiplus::Graphics *graphics);
	
	/// Switches the state
	void SwitchState();
	
	/** Get the state of the bunker
	 * \return The state of the bunker */
	int GetBunkerState() { return mState; }
	
	/** set the state of the bunker
	 * \param i The state to set the bunker to */
	void SetBunkerState(int i) { mState = i; }
	
	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitBunker(this); }

private:
	std::unique_ptr<Gdiplus::Bitmap>mBunkerImage; ///< bunker base image
	int mState = 0; ///< bunker state tracker
	std::unique_ptr<Gdiplus::Bitmap> mImageState1; ///< bucker damage state 1
	std::unique_ptr<Gdiplus::Bitmap> mImageState2; ///< bucker damage state 2
	std::unique_ptr<Gdiplus::Bitmap> mImageState3; ///< bucker damage state 3
	std::unique_ptr<Gdiplus::Bitmap> mImageState4; ///< bucker damage state 4
	std::unique_ptr<Gdiplus::Bitmap> mImageState5; ///< bucker damage state 5
};

