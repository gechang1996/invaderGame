/**
 * \file Invader.cpp
 *
 * \author Chang Ge
 *
 * Class that describes a general invader
 */

#include "stdafx.h"
#include <string>
#include "Invader.h"
#include "Game.h"
#include "InvaderCounter.h"

using namespace Gdiplus;
using namespace std;

/// The max amount an invader can move
const double MaxMove = 100;
/// The Y move amount
const double MoveY = 100;
/// The X move amount
const double MoveX = 100;
/// The negative X move amount
const double NegMoveX = -100;
/// The initial move amount
const double MoveInitial = 50;
/// X position
const int X = 20;
/// Y position
const int Y = 50;
/// First invader count threshold
const int Count1 = 30;
/// Second invader count threshold
const int Count2 = 20;
/// Third invader count threshold
const int Count3 = 10;
/// Last invader count threshold
const int Count4 = 5;


/**
 * Constructor
 * \param game The game the invader will go into
 */
CInvader::CInvader(CGame *game) :
	CItem(game)
{
	mCountLine = 10;
	SetSpeed(MoveX, MoveY);
}

/**
* Deconstructor
*/
CInvader::~CInvader()
{
}

/**
* Describes how the indaver will step across the game board
*/
void CInvader::Step()
{
	//While less than 20 steps have been taken, take a normal step
	if (mCountLine < 20)
	{

		SetLocation(GetX() - mXMove, GetY());
		if (mFlag == 0)
		{
			mFlag = 1;
		}
		else
		{
			mFlag = 0;
		}
		mCountLine++;
	}
	//If more than 20 steps have been taken
	else
	{
		mCountLine = 0;
		SetLocation(GetX() - mXMove, GetY() + 15);
		if (mFlag == 0)
		{
			mFlag = 1;
		}
		else
		{
			mFlag = 0;
		}
		//reverse the x direction
		mXMove = -mXMove;

	}
	mCountMove = 0;
	mCountLine++;

}

/**
 * Handle updates in time of the invader
 *
 * This is called before we draw and allows the invder to move.
 * Count the elapse until we've built enough time to take a step
 * \param elapsed Time elapsed since the class call
 */
void CInvader::Update(double elapsed)
{
	CInvaderCounter visitor;
	Getter()->Accept(&visitor);
	int cnt = visitor.GetNumInvaders();
	//Sets the speed of the invader reletive to the number of
	//invaders in steps
	if (cnt >= Count1)
	{
		mSpeed = 0.5;
	}
	else if (cnt >= Count2)
	{
		mSpeed = 0.25;
	}
	else if (cnt >= Count3)
	{
		mSpeed = 0.05;
	}
	else if (cnt >= Count4)
	{
		mSpeed = .025;
	}
	else
	{
		mSpeed = 0.01;
	}
	
	//If the invader has built up enough time (reletive to the speed),
	//Take a step
	if (mCountMove >= mSpeed)
	{
		Step();
		Getter()->RandomShootBall(GetX() + X, GetY() - Y);
		mCountMove -= mSpeed;
	}
	else
	{
		mCountMove+= elapsed;
	}

}

/**
* Sets the invader's location to a specific coordinate
* param x The x coord
* param y The y coord
*/
void CInvader::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
}

/**
* Moves an invader at a specific coordinate into the queue to be deleted
* param x The x coord
* param y The y coord
*/
void CInvader::DeleteInvader(double x, double y)
{
	shared_ptr<CItem> item = Getter()->HitTest(int(x), int(y));
	Getter()->AddToRemove(item);
}

/**
* Increases MSU/Sparty's score when and invader gets killed
*/
void CInvader::MSUPlusOne()
{
	Getter()->GetScore()->UpdateMSUScore();
}

/**
* Updates the invader's mIsShot property, indicating they've been shot
*/
void CInvader::SetShoot()
{
	mIsShot = 1;
}

/**
 * Draw the invader's step images
 * \param graphics The graphics to draw on
 */
void CInvader::Draw(Graphics *graphics)
{
	if (!GetFlag())
	{
		int wid = mImage1->GetWidth();
		int hit = mImage1->GetHeight();

		graphics->DrawImage(mImage1.get(),
			(int)(GetX() - mOffsetLeft), (int)(GetY() + mOffsetDown - hit),
			wid, hit);
	}
	else
	{
		int wid = mImage2->GetWidth();
		int hit = mImage2->GetHeight();

		graphics->DrawImage(mImage2.get(),
			(int)(GetX() - mOffsetLeft), (int)(GetY() + mOffsetDown - hit),
			wid, hit);
	}
}
