/**
 * \file InvaderNebraska.cpp
 *
 * \author Chang Ge
 */

#include "stdafx.h"
#include <string>
#include "InvaderNebraska.h"

using namespace Gdiplus;
using namespace std;

/// Nebraska invader filename 1
const wstring CInvaderNebraskaImageName1 = L"images/invaderNa.png";
/// The other nebraska image filename
const wstring CInvaderNebraskaImageName2 = L"images/invaderNb.png";
/// X Runaway speed
double RunawaySpeedX = 200;
/// The Y runaway speed
double RunawaySpeedY = 200;
/// The angular speed to run
double RunawayAngularSpeed = 10;
/// The distance speed to run
double RunawayDistanceSpeed = 150;

/**
* destructor
*/
CInvaderNebraska::~CInvaderNebraska()
{
}

/** Constructor
 * \param game The game this is a member of
*/
CInvaderNebraska::CInvaderNebraska(CGame *game) :
	CInvader(game)
{
	SetImage(CInvaderNebraskaImageName1);
	LoadImage(mImage1, CInvaderNebraskaImageName1);
	LoadImage(mImage2, CInvaderNebraskaImageName2);
	
	
}

/**
 * update the nebraska invader
 * \param elapsed The amount of elapsed time
 */
void CInvaderNebraska::Update(double elapsed)
{
	if (GetShoot() == 0) 
	{
		CInvader::Update(elapsed);
	}
	else
	{
		if (mTimer == 0)
		{
			MSUPlusOne();
		}

		SetLocation(GetX() + elapsed * RunawaySpeedX, GetY() + elapsed * RunawaySpeedY);
		mAngle += elapsed * RunawayAngularSpeed;
		mDistance += elapsed * RunawayDistanceSpeed;

		double x = GetX() + mDistance * cos(mAngle);
		double y = GetY() + mDistance * sin(mAngle);
		SetLocation(x, y);
		mTimer += elapsed;
	}
}

/**
 * Draw the nebraska invader
 * \param graphics The graphics to draw on
 */
void CInvaderNebraska::Draw(Graphics *graphics)
{
	//No special case images means general case draw
	CInvader::Draw(graphics);
}
