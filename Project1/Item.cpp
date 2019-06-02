/**
 * \file Item.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <memory>
#include "Item.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/// How much we offset drawing the tile to the left of the center
const int OffsetLeft = 64;
/// How much we offset drawing the tile above the center
const int OffsetDown = 32;

/// Inside tolerance for item move
const double InsideTolerance = 58;

/// The other inside tolerance 
const double InsideTolerance2 = 120;

/** 
* Constructor
* \param game The game this item is a member of
*/
CItem::CItem(CGame *game) : mGame(game)
{
}

/**
* Destructor
*/
CItem::~CItem()
{
}

/**
 * Draw our item
 * \param graphics The graphics context to draw on
 */
void CItem::Draw(Graphics *graphics)
{
	if (mItemImage != nullptr)
	{
		int wid = mItemImage->GetWidth();
		int hit = mItemImage->GetHeight();

		graphics->DrawImage(mItemImage.get(),
			int(mPositionX) - OffsetLeft, int(mPositionY) + OffsetDown - hit,
			wid, hit);
	}
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const wstring &file)
{
	if (!file.empty())
	{
		wstring filename =  file;
		mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
		if (mItemImage->GetLastStatus() != Ok)
		{
			wstring msg(L"Failed to open ");
			msg += filename;
			AfxMessageBox(msg.c_str());
			return;
		}
	}
	else
	{
		mItemImage.release();
	}
}

/**
 * Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CItem::HitTest(int x, int y)
{
	return (abs(x - mPositionX) + abs(y - mPositionY) * 2) <= InsideTolerance;
}

/**
 * Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \returns true if hit
 */
bool CItem::HitTest2(int x, int y)
{
	return (abs(x - mPositionX) + abs(y - mPositionY) * 2) <= InsideTolerance2;
}

/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CItem::LoadImage(unique_ptr<Bitmap> &image, wstring name)
{
	wstring filename = name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

