/**
 * \file Bunker.cpp
 *
 * \Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "Bunker.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/// image location of bunker damage state 1 image
const wstring Bunker1 = L"images/stadium.png"; 
/// image location of bunker damage state 2 image
const wstring Bunker2 = L"images/stadium1.png"; 
/// image location of bunker damage state 3 image
const wstring Bunker3 = L"images/stadium2.png"; 
/// image location of bunker damage state 4 image
const wstring Bunker4 = L"images/stadium3.png"; 
/// image location of bunker damage state 5 image
const wstring Bunker5 = L"images/stadium4.png"; /// image location of bunker damage state 5 image
/// How much we offset drawing the tile to the left of the center
const static int OffsetLeft = 64;
/// How much we offset drawing the tile above the center
const static int OffsetDown = 32;

/**
 * Constructor
 * \param game The game we are in
 */
CBunker::CBunker(CGame *game) : CItem(game)
{	
	SetImage(Bunker1);
	LoadImage(mImageState1, Bunker1);
	LoadImage(mImageState2, Bunker2);
	LoadImage(mImageState3, Bunker3);
	LoadImage(mImageState4, Bunker4);
	LoadImage(mImageState5, Bunker5);
	SetSpeed(0, 0);
}

/*
* Destructor
*/
CBunker::~CBunker()
{
}
/**
* Draw's the bunker's image onto the screen
* \param graphics A pointer to the graphics object we will draw onto
*/
void CBunker::Draw(Gdiplus::Graphics *graphics)
{
	if (mState==0){
		int wid = mImageState1->GetWidth();
		int hit = mImageState1->GetHeight();

		graphics->DrawImage(mImageState1.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mState==1)
	{
		int wid = mImageState2->GetWidth();
		int hit = mImageState2->GetHeight();

		graphics->DrawImage(mImageState2.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mState == 2)
	{
		int wid = mImageState3->GetWidth();
		int hit = mImageState3->GetHeight();

		graphics->DrawImage(mImageState3.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mState == 3)
	{
		int wid = mImageState4->GetWidth();
		int hit = mImageState4->GetHeight();

		graphics->DrawImage(mImageState4.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mState == 4)
	{
		int wid = mImageState5->GetWidth();
		int hit = mImageState5->GetHeight();

		graphics->DrawImage(mImageState5.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
}

/*
* increases the bunker's state
*/
void CBunker::SwitchState()
{
	//if the state is less than the threshold, increase it by one
	if (mState <= 3)
	{
		mState += 1;
	}
	//when we pass the threshold, move the bunker object to be deleted
	else if (mState >= 4)
	{
		std::shared_ptr<CItem> item = Getter()->HitTest(int(GetX()), int(GetY()));
		Getter()->AddToRemove(item);
	}
}

