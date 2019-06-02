/**
 * \file InvaderIowa.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "InvaderIowa.h"

using namespace Gdiplus;
using namespace std;

/// X speed constant
const double Speedx = 400;
/// Constant used for random nums
const int Hundred = 100;
/// Another random constant 
const int Halfhundred = 50;
/// First Iowa image 
const wstring InvaderIowaImageName1 = L"images/invaderIa.png";
/// Second Iowa image
const wstring InvaderIowaImageName2 = L"images/invaderIb.png";

/**
* Destructor
*/
CInvaderIowa::~CInvaderIowa()
{
}

/** 
* Constructor
* \param game The game this is a member of
*/
CInvaderIowa::CInvaderIowa(CGame *game) :
	CInvader(game)
{
	SetImage(InvaderIowaImageName1);
	LoadImage(mImage1, InvaderIowaImageName1);
	LoadImage(mImage2, InvaderIowaImageName2);

	if (rand() % Hundred < Halfhundred)
	{
		SetSpeed(Speedx, 0);
	}
	else
	{
		SetSpeed(-Speedx, 0);
	}
}

/**
 * Update the iowa invader
 * \param elapsed - amount of time elapsed
 */
void CInvaderIowa::Update(double elapsed)
{
	if (GetShoot() == 1)
	{
		if (mTimer == 0)
		{
			MSUPlusOne();
		}
		SetLocation(GetX() + GetSpeedX() * elapsed,
			GetY() + GetSpeedY() * elapsed);
		
		mTimer += elapsed;
	}
	else
	{
		CInvader::Update(elapsed);
	}
}

/**
 * Draw the Iowa invader
 * \param graphics The graphics to draw on
 */
void CInvaderIowa::Draw(Graphics *graphics)
{
	//No special case images means general case draw
	CInvader::Draw(graphics);
}
