/**
 * \file InvaderOhioState.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "InvaderOhioState.h"

using namespace Gdiplus;
using namespace std;

/// Ohio state invader filename 1
const wstring CInvaderOhioStateImageName1 = L"images/invaderOSa.png";
/// Ohio state invader file name 2
const wstring CInvaderOhioStateImageName2 = L"images/invaderOSb.png";
/// Minimum speed of ohio state
const double Minspeed = 100;
/// Number used for random gen
const int Hundreds = 600;
/// Number also used for random gen
const int Hundred = 100;

/**
* destructor
*/
CInvaderOhioState::~CInvaderOhioState()
{
}

/** 
* Constructor
* \param game The game this is a member of
*/
CInvaderOhioState::CInvaderOhioState(CGame *game) :
	CInvader(game)
{
	SetImage(CInvaderOhioStateImageName1);
	LoadImage(mImage1, CInvaderOhioStateImageName1);
	LoadImage(mImage2, CInvaderOhioStateImageName2);
	double XSpeed = (rand() % Hundreds) + Minspeed;
	double YSpeed = (rand() % Hundreds) + Minspeed;
	if (rand() % Hundred < 50)
	{
		XSpeed = -XSpeed;
	}
	if (rand() % Hundred < 50)
	{
		YSpeed = -YSpeed;
	}
	SetSpeed(XSpeed, YSpeed);
}

/**
 * Update the ohio state invader
 * \param elapsed Amount of time elapsed
 */
void CInvaderOhioState::Update(double elapsed)
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
 * Draw the ohio state invader
 * \param graphics The graphics to draw on
 */
void CInvaderOhioState::Draw(Graphics *graphics)
{
	//No special case images means general case draw
	CInvader::Draw(graphics);
}

