/**
 * \file Score.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <sstream>
#include <string>
#include "Game.h"
#include "Score.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game The game this is a part of
 */
CScore::CScore(CGame *game)
{
}

/*
* Destructor
*/
CScore::~CScore()
{
}

/**
 * Function to display the game's score
 * \param graphics - game's graphics to draw on
 */
void CScore::DisplayScore(Graphics *graphics)
{
	std::wstringstream msu_str;
	msu_str << L"MSU: " << mMSUScore;
	std::wstringstream invader_str;
	invader_str << L"Invaders: " << mInvaderScore;
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 18);

	SolidBrush white(Color::White);

	graphics->DrawString(msu_str.str().c_str(), -1, &font, PointF(-335, 45), &white);
	graphics->DrawString(invader_str.str().c_str(), -1, &font, PointF(85, 45), &white);
}


/**
 * Reset the score to 0
 */
void CScore::Reset()
{
	mMSUScore = 0;
	mInvaderScore = 0;
}
