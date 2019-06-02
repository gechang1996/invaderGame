/**
 * \file GameOver.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "GameOver.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/// Filename for game over image
const wstring GameOverimg = L"images/new-game.png";
/// How much we offset drawing the tile to the left of the center
const static int OffsetLeft = 64;
/// How much we offset drawing the tile above the center
const static int OffsetDown = 32;
/// Y position of the game over
const int Ypos = 500;
/// Inside tolerance of game over
const int InsideTolerance = 64;


/**
 * Constructor
 * \param game The game this is a part of
 */
CGameOver::CGameOver(CGame *game)
{
	SetImage(GameOverimg);
}


/**
 * Destructor
 */
CGameOver::~CGameOver()
{
}

/**
 * Draw the game over 
 * \param graphics The graphics to draw on
 */
void CGameOver::Draw(Graphics *graphics)
{
	if (mGameover != nullptr)
	{
		int wid = mGameover->GetWidth();
		int hit = mGameover->GetHeight();

		graphics->DrawImage(mGameover.get(),
			int(0) - OffsetLeft, int(Ypos) + OffsetDown - hit,
			wid, hit);
	}
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CGameOver::SetImage(const std::wstring &file)
{
	if (!file.empty())
	{
		wstring filename = file;
		mGameover = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
		if (mGameover->GetLastStatus() != Ok)
		{
			wstring msg(L"Failed to open ");
			msg += filename;
			AfxMessageBox(msg.c_str());
			return;
		}
	}
	else
	{
		mGameover.release();
	}
}


/**
 * Test if user hit button
 * \param x X location to test
 * \param y Y location to test
 * \returns 
 */
bool CGameOver::HitTest(double x, double y)
{
	if (x >= -64 && x <= 133 && y >= 420 && y <= 530) 
	{
		return true;
	}
	return false;
}